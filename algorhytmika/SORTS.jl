"""ВОПРОС 1: сортировка пузырьком"""
function bubbleSortModF!(array::AbstractVector)
    for i in 1:length(array)
        for j in 1:length(array)-i
            if array[j] > array[j+1]
                swap!(array, j, j+1)
            end
        end
    end
end

"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""

"""ВОПРОС 15: сортировка пузырьком(двухсторонняя)"""
function bubbleSortModS!(array::AbstractVector)
    counter = 0
    start = 2
    stop = length(array)-1
    step = 1
    for i in 1:(length(array)/2+1)
        for j in start:step:stop
            if step == 1
                if array[j] > array[j+step]
                    swap!(array, j, j+step)
                end
            end
            if step == -1
                if array[j] < array[j+step]
                    swap!(array, j, j+step)
                end
            end
        end
        if step == 1
            stop -= 1
        elseif step == -1
            start += 1
        end
        step = -step
        temp = start
        start = stop
        stop = temp
    end
end

"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""

"""ВОПРОС 7: сортировка вставками"""
"""Сортировка вставками"""
function insertionSort!(array::AbstractVector)
    for i in 2:length(array)
        for j in i-1:-1:1
            if array[i] < array[j]
                swap!(array, i, j)
            end
        end
    end
end

"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""

"""ВОПРОС 16: сортировка Шелла"""
function shellSort!(array::AbstractVector)
    gap = length(array)
    while gap > 0
        for i in 1:lastindex(array)-gap
            j = i
            while j >= firstindex(a) && array[j] > array[j+gap]
                swap!(array, j, j+gap)
                j -= gap
            end
        end
        gap = div(gap, 2)
    end
end

"""ВОПРОС 17: сортировка расчёской"""
function comb_sort!(array::AbstractVector)
    gap = length(array)
    while gap != 0
        for i in firstindex(array):lastindex(array)-gap
            if array[i] > array[i+gap]
                array[i], array[i+gap] = array[i+gap], array[i]
            end
        end
        gap-=1
    end
    return array
end

"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""

"""ВОПРОС 18: сортировка слиянием"""
function merge_sort!(a)
    b = similar(a) 
    N = length(a)
    n = 1 
    while n < N
        K = div(N,2n) 
        for k in 0:K-1
            merge!(@view(a[(1:n).+k*2n]), @view(a[(n+1:2n).+k*2n]), @view(b[(1:2n).+k*2n]))
        end
        if N - K*2n > n
            merge!(@view(a[(1:n).+K*2n]), @view(a[K*2n+n+1:end]), @view(b[K*2n+1:end]))
        elseif 0 < N - K*2n <= n
            b[K*2n+1:end] .= @view(a[K*2n+1:end])
        end
        a, b = b, a
        n *= 2
    end
    if isodd(log2(n))
        b .= a 
        a = b
    end
    return a
end

"""Вспомогательная функция для сортировки слияниями"""
function Base.merge!(a1, a2, a3)::Nothing
    i1, i2, i3 = 1, 1, 1
    @inbounds while i1 <= length(a1) && i2 <= length(a2)
        if a1[i1] < a2[i2]
            a3[i3] = a1[i1]
            i1 += 1
        else
            a3[i3] = a2[i2]
            i2 += 1
        end
        i3 += 1
    end
    if i1 > length(a1)
        a3[i3:end] .= @view(a2[i2:end])
    else
        a3[i3:end] .= @view(a1[i1:end])
    end
    nothing
end

"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""

"""ВОПРОСЫ 12, 13, 14: всё связанное с сортировкой Хоара"""
"""Сортировка Хоара"""
function quick_sort!(A)
    length(A) <= 1 && return A
    N = length(A)
    left, right = part_sort!(A, A[rand(1:N)])
    quick_sort!(left)
    quick_sort!(right)
    return A
end

"""Вспомогательная сортировка"""
function part_sort!(A, b)
    N = length(A)
    K, L, M = 0, 0, N
    @inbounds while L < M
        if A[L+1] == b
            L += 1
        elseif A[L+1] > b
            A[L+1], A[M] = A[M], A[L+1]
            M -= 1
        else
            L += 1; K += 1
            A[L], A[K] = A[K], A[L]
        end
    end
    return @view(A[1:K]), @view(A[M+1:N])
end

"""Вычисление k-ой порядковой статистики методом Хоара"""
function order_statistics!(A::AbstractVector{T}, i::Integer)::T where T
    function find(index_range)
        left_range, right_range = part_sort!(A, index_range, A[rand(index_range)])
        if i in left_range
            return find(left_range) 
        elseif i in right_range
            return find(right_range)
        else
            return A[i]
        end
    end
    find(firstindex(A):lastindex(A))
end

@inline function part_sort!(A, index_range::AbstractUnitRange, b)
    K, L, M = index_range[1]-1, index_range[begin]-1, index_range[end]
    @inbounds while L < M 
        if A[L+1] == b
            L += 1
        elseif A[L+1] > b
            A[L+1], A[M] = A[M], A[L+1]
            M -= 1
        else
            L += 1; K += 1
            A[L], A[K] = A[K], A[L]
        end
    end    
    return index_range[begin]:K, M+1:index_range[end]
end

"""Вычисление медианы массива"""
function median(A::AbstractVector{T})
    if length(A)%2==0
        return order_statistics!(A, length(A)/2)
    else
        return (order_statistics!(A, length(A)/2)+order_statistics!(A, length(A)/2+1))/2
    end
end

"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""
"""///////////////////////////////////////////////////////////////////////////"""

"""Алгоритм вычисления среднего квадратического отклонения от среднего значения массива"""
function standard_deviation(A)
    Sx = 0
    Sx2 = 0
    for i in firstindex(A):lastindex(A)
        Sx += i
        Sx2 += i*i
    end
    return sqrt((Sx2 / length(A)) - ((Sx/ length(A))*(Sx/ length(A))))
end