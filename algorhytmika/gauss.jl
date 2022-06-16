using LinearAlgebra

function reverse_gauss_1(A::AbstractMatrix{T}, b::AbstractVector{T}) where T
    x = similar(b)
    N = size(A, 1)
    for k in 0:N-1
        x[N-k] = (b[N-k] - sum(A[N-k,N-k+1:end] .* x[N-k+1:end])) / A[N-k,N-k]
    end
    return x
end 

function reverse_gauss_2(A::AbstractMatrix{T}, b::AbstractVector{T}) where T
    x = similar(b)
    N = size(A, 1)
    for k in 0:N-1
        x[N-k] = (b[N-k] - sum(@view(A[N-k,N-k+1:end]) .* @view(x[N-k+1:end]))) / A[N-k,N-k]
    end
    return x
end

function reverse_gauss_3(A::AbstractMatrix{T}, b::AbstractVector{T}) where T
    x = similar(b)
    N = size(A, 1)
    for k in 0:N-1
        x[N-k] = (b[N-k] - dot(@view(A[N-k,N-k+1:end]), @view(x[N-k+1:end]))) / A[N-k,N-k]
    end
    return x
end

function reverse_gauss_4(A,b)
    #A - транспонированная матрица 
    N = size(A, 2)
    x = Vector{eltype(Ab)}(undef,N)
        
    for k in 0:N-1
        x[N-k] = (b[N-k] - dot(@view(A[N-k+1:N, N-k]), @view(x[N-k+1:N])))/A[N-k,N-k]
    end
    return x
end


function reverse_gauss_5(Ab)
    #Ab - транспонированная расширенная матрица 
    N = size(A, 2)
    x = Vector{eltype(Ab)}(undef,N)
           
    for k in 0:N-1
        x[N-k] = (Ab[N-k, N] - dot(@view(Ab[N-k+1:N, N-k]), @view(x[N-k+1:N])))/Ab[N-k,N-k]
    end
    return x
end 

function upper_triangular(N::Integer)
    A = randn(N,N)
    _, A = lu(A)
    return A
end

N=10_000
A = upper_triangular(N)
b = ones(N)
At=A'
Abt=[A b]'

println("1:")
@time reverse_gauss_1(A,b);
println("2:")
@time reverse_gauss_2(A,b);
println("3:")
@time reverse_gauss_3(A,b);
println("4:")
@time reverse_gauss_3(At,b); # - это лучший вариант

println("5:")
@time reverse_gauss_5(Abt);
println("...................")
