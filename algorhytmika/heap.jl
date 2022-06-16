"""преобразование массива в кучу"""
function heap!(array)
    N = length(array)
    for i in 1:N÷2
        if array[i] < array[2i]
            array[i], array[2i] = array[2i], array[i]
        end
        
        if 2i+1 <= N && array[i] < array[2i+1]
            array[i], array[2i+1] = array[2i+1], array[i]
        end
    end
    return array
end

"""
    up!(heap::AbstractVector, index)

"Поднимает" элемент с индексом index к вершине куче, пока этот элемент не займет свое "правильное" место в куче, и возвращает наименьший из индексов всех перемещенных при этом элементов кучи.
"""
function up!(heap::AbstractVector, index)
    @assert i <= length(heap)
    is_ord = false
    while index > 1 && is_ord == false
        is_ord = true
        if heap[index] > heap[index÷2]
            heap[index], heap[index÷2] = heap[index÷2], heap[index]
            is_ord = false
        end

        if heap[index] > heap[(index-1)÷2]
            heap[index], heap[(index-1)÷2] = heap[(index-1)÷2], heap[index]
            is_ord = false
        end     
        
        current_index = index
        if isodd(i)
            index ÷= 2
        else
            index = (index-1)÷2
        end
    end
    return current_index
end

"""
    down!(heap::AbstractVector, index)::Nothing

"Опускает" элемент с индексом index ближе к концу кучи, пока этот элемент не займет свое "правильное" место в куче.
"""
function down!(heap::AbstractVector, index)::Nothing
    N = length(heap)
    while index < N÷2
        if heap[index] < heap[2index]
            heap[index], heap[2index] = heap[2index], heap[index]
        end
        if 2index+1 <= N && heap[index] < heap[2index+1]
            heap[index], heap[2index+1] = heap[2index+1], heap[index]
        end
        index *= 2
    end
end

"""
    push!(heap::AbstractVector, new_elem)::Nothing

Добавляет новый элемент в кучу, представленную массивом.
"""
function Base.push!(heap::AbstractVector, new_elem)::Nothing
    push!(heap, new_elem)
    up!(heap, lastindex(heap))
end


"""
    pop!(heap::AbstractVector, new_elem)

Извлекает из кучи, представленной массивом, и возвращает элемент с наивысшим приоритетом.
"""
function Base.pop!(heap::AbstractVector, new_elem)
    heap[begin], heap[end] = heap[end], heap[begin]    
    max_value = pop!(heap)
    down!(heap, firstindex(heap))
    return max_value
end

"""
dec_priority!(heap::AbstractVector{T}, index::Integer, new_value::T)::Nothing where T

Выполняет необходимое перестраивание максимальной кучи при замене heap[index] мЕньшим значением new_value.
"""
function dec_priority!(heap::AbstractVector{T}, index::Integer, new_value::T)::Nothing where T
    @assert new_value <= heap[index]
    prioity[index] = new_value
    down!(heap, index)
end

"""
inc_priority!(heap::AbstractVector{T}, index::Integer, new_value::T)::Nothing where T

Выполняет необходимое перестраивание максимальной кучи при замене heap[index] бОльшим значением new_value.
"""
function inc_priority!(heap::AbstractVector{T}, index::Integer, new_value::T)::Nothing where T
    @assert new_value >= heap[index]
    prioity[index] = new_value
    up!(heap, index)
end

"""Пирамидальная сортировка
1.Преобразуем исходный массив в кучу (с помощью функции heap!).

2.Поменяем местами первый элемент массива (после предыдущего шага он будет максималным) с последним (тем самым последний элемент массива окажется на "своем" окончательном месте), и переместим первый элемент массива на "правильное" место в куче. С использованием функции down! на это потребуется O(\log N)O(logN) элементарных операций.

3.Длину сортируемой части массива уменьшим на 1 и перейдем к пункту 2, и т.д. пока длина сортируемой части станет раной 3 (первые три элемента кучи всегда отсортированы).

"""

function heap_sort!(heap::AbstractVector)
    heap = heap!(heap) 
    # здесь heap! - это именно функция, преобразующая массивив в максимальную кучу, а не конструктор типа Heap!
    N = length(heap)  
    #ИНВАРИАНТ: heap[1:N] - это максимальная куча && heap[N+1:end] - это отсортированная часть массива
    while N > 3
        heap[1], heap[N] = heap[N], heap[1]
        N -= 1
        down!(@view(heap[1:N]), 1) 
        # - это вызов метода down!(::AbstractVector, Any), а не метода down!(::Heap!, ::Any)
    end
    return heap
end