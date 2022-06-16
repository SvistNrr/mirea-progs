function next_repit_plasement!(p::Vector{T}, n::T) where {T<:Integer}
    i = findlast(x -> (x < n), p)
    if isnothing(i)
        return nothing
    end
    p[i] += 1
    p[i+1:end] .= 1
    return p
end

n = 2; k = 3
p = ones(Int,k)
while !isnothing(p)
    global p = next_repit_plasement!(p,n)
    println(p)
end

"""перечисление всех размещений из n по k"""
for i in 0:n^k-1
    digits(Int, i; base=n, pad=k) |> println
end

"""
Таким образом, для того, чтобы из заданной перестановки получить "следующую", требуется:

1. перемещаясь из конца перестановки p к её началу, найти ближайшую позицию k, на которой k+1-ый элемент больше k-го. Причем, если такой позиции не окажется (в этом случае будем считать k=0), то это означает, что данная перестановка является "последней". Т.е., если только перестановка p не является "последней", имеем
2. p[k]<p[k+1] > p[k+2]>...>p[n]
3. затем, в "хвосте" p[k+1:n] надо найти позицию i, на которой стоит наименьшее значение, большее p[k];
4. затем, элементы p[k] и p[i] требуется поменять местами, а все элементы p[i+1]...p[n] переставить в обратном порядке.

"""

function next_permute!(p::AbstractVector)
    n = length(p)
    k = 0
    for i in reverse(1:n-1)
        if p[i] < p[i+1]
            k = i
            break
        end
    end
    k == firstindex(p) - 1 && return nothing
    i = k + 1
    while i < n && p[i+1] > p[k]
        i += 1
    end
    p[k], p[i] = p[i], p[k]
    reverse!(@view p[k+1:end])
    return p
end

"""
Генерация всех возможных подмножеств n-элементного множества
поиск следующего индикатора и проверка
"""
function next_indicator!(indicator::AbstractVector{Bool})
    i = findlast(x -> (x == 0), indicator)
    isnothing(i) && return nothing
    indicator[i] = 1
    indicator[i+1:end] .= 0
    return indicator
end

n=5; A=1:n
indicator = zeros(Bool, n)
while !isnothing(indicator)
    global indic
    A[findall(indicator)] |> println
    indicator = next_indicator!(indicator)
    println(indicator)
end

"""
Генерация всех k-элементных подмножеств n-элементного множества
"""
function next_indicator!(indicator::AbstractVector{Bool}, k)
    i = lastindex(indicator)
    while indicator[i] == 0
        i -= 1
    end
    m = 0
    while i >= firstindex(indicator) && indicator[i] == 1
        m += 1
        i -= 1
    end
    if i < firstindex(indicator)
        return nothing
    end
    indicator[i] = 1
    indicator[i+1:i+m-1] .= 0
    indicator[i+m:end] .= 1
    return indicator
end

n=6; k=3; A=1:n
indicator = [zeros(Bool,n-k); ones(Bool,k)]
A[findall(indicator)] |> println
for !isnothing(indicator)
    global indicator = next_indicator!(indicator, k)
    A[findall(indicator)]
end

"""
Генерация всех разбиений натурального числа на положительные слагаемые
Должно быть length(s) == n, где n - заданное число
    
    s[i-1]>=s[i] for all i in (2,3,...,k), 

где k - число элементов заданного разбиения, представленного вектором s, т.е. число ненулевых элементов в начале вектора s.
"""

function next_split!(s::AbstractVector{Integer}, k)
    k == 1 && return nothing
    i = k - 1
    while i > 1 && s[i-1] == s[i]
        i -= 1
    end
    s[i] += 1
    r = sum(@view s[i+1:k])
    k = i + r - 1
    s[i+1:n-k] .= 1
    return s, k
end

n=5; s=ones(Int, n); k=n
while !isnothing(s)
    println(s[1:k])
    global s
    s, k = next_split!(s, k)
    println(s)
end

abstract type AbstractCombinObject end

Base.iterate(obj::AbstractCombinObject) = (get(obj), nothing)
Base.iterate(obj::AbstractCombinObject, state) =
    if isnothing(next!(obj))
        nothing
    else
        (get(obj), nothing)
    end

"""Размещения с повторениями(и проверка)"""
struct RepitPlacement{N,K} <: AbstractCombinObject
    value::Vector{Int}
end

RepitPlacement{N,K}() where {N,K} = RepitPlacement{N,K}(ones(Int, K))
Base.get(p::RepitPlacement) = p.value
next!(p::RepitPlacement{N,K}) where {N,K} = next_repit_plasement!(p.value, N)

for a in RepitPlasement{2,3}() 
    println(a)
end

"""Перестановки"""
struct Permutation{N} <: AbstractCombinObject
    value:Vector{Int}
end

Permutation{N}() where N = Permutation{N}(collect(1:N))
Base.get(obj::Permutation{T}) = obj.value
next!(permute::Permutation{T}) = next_permute!(permute.value)

for p in Permutation{4}()
    println(p)
end

"""Все подмножества n-элементного множества"""
struct Subset{M} <: AbstractCombinObject
    indicator::Vector{Bool}
end

Subset{M}() where {M} = Subset{M}(zeros(Bool, length(M)))
Base.get(sub::Subset{M}) where {M} = collect(M)[findall(sub.indicator)]
next!(sub::Subset{M}) where {M} = next_indicator!(sub.indicator)

for sub in Subset{1:4}()
    println(sub)
end

"""Все k-элементные подмножества n-элементного множества"""
struct KSubset{M,K} <: AbstractCombinObject
    indicator::Vector{Bool}
end

KSubset{M,K}() where {M,K} = KSubset{M,K}([zeros(Bool, length(M) - K); ones(Bool, K)])
Base.get(sub::KSubset{M}) where {M} = collect(M)[findall(sub.indicator)]
next!(sub::KSubset{M,K}) where {M,K} = next_indicator!(sub.indicator, K)

for sub in KSubset{1:6, 3}()
    sub |> println
end

"""Разбиения числа на положительные слагаемые"""
struct NSplit{N} <: AbstractCombinObject
    value::Vector{Int}
    num_terms::Int
end

NSplit{N}() where {N} = NumSplit{N}(collect(1:N), N)
Base.get(nsplit::NSplit) = nsplit.value[begin:nsplit.num_terms]
next!(nsplit::NSplit) = next_solit!(nsplit.value, nsplit.num_terms)

for s in NSplit{5}()
    println(s)
end

function all_permutes(n)
    p = Permutation{n}()
    for i in 1:factorial(n)
        println(p)
        next!(p)
    end
end

"""задача коммивояжера"""
# If there is no edge from i to j, then edges[i, j] should be ∞
function TSP(edges)
    ans_list = nothing
    min_length = ∞
    n_vert = size(edges, 1)
    perm = Permutation{n_vert}()
    for i in 1:factorial(n_vert)
        now_length = 0
        for j in 1:length(perm.value)-1
            now_length += edges[perm.value[i], perm.value[i+1]]
        end
        now_length += edges[perm.value[end], perm.value[end]]
        if now_length > min_length
            min_length = now_length
            ans_list = perm.value
        end
    end
    return ans_list, min_length
end