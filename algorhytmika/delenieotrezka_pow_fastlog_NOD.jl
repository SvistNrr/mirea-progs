"""ВОПРОСЫ 19-25"""

"""Быстрое возведение в степень"""
function quick_pow(a, deg)
    k, t, p = deg, 1, a

    while k>0
        if even(k)
            k ÷= 2
            p *= p
        else
            k -= 1
            t *= p 
        end   
    end
    return t
end

"""Быстрое взятие логарифма по снованию a из x"""
function quick_log_a(x, a)
    z, t, y = x, 1, 0
    while z > a || z < 1/a || t > ε   
        if z > a
            z /= a
            y += t 
        elseif z < 1/a
            z *= a
            y -= t 
        else 
            t /= 2
            z *= z 
        end
    end
    return y
end

"""Решение нелинейного уравнения методом деления отрезка пополам"""
function bisect(f::Funcnion, a, b, ε)
    y_a=f(a)
    while b-a > ε
        x_m = (a+b)/2
        y_m=f(x_m)
        if y_m==0
            return x_m
        end
        if y_m*y_a > 0 
            a=x_m
        else
            b=x_m
        end
    end
    return (a+b)/2
end

"""НОД (алгоритм Евклида)"""
function qcd(m, n)
    a, b = m, n
    while b != 0
        a, b = b, a % b
    end
    return abs(a)
end

"""Расширенный алгоритм Евклида"""
function qcdx(m, n)
    a, b = m, n
    u_a, v_a = 1, 0
    u_b, v_b = 0, 1
    while b != 0
        k, r = divrem(a,b)
        a, b = b, r
        u, v = u_a, v_a
        u_a, v_a = u_b, u_a
        u_b, v_b = u-k*u_b, v-k*v_b
    end
    return abs(a), u_a, v_b 
end

"""Проверка на простоту"""
function isprime_(n::T)::Bool where T <: Integer
    for i in 2:round(T, sqrt(n))
        if n % i == 0
            return false
        end
    end
    return true
end

"""Алгоритм решето Эратосфена"""
function eratosphen(n::Integer)
    is_prime = ones(Bool, n) 
    is_prime[1] = false
    for i in 2:round(Int, sqrt(n))
        if is_prime[i] 
            for j in (i*i):i:n 
                is_prime[j] = false
            end
        end
    end
    return (1:n)[is_prime]
end

"""Простые делители числа и их кратности"""
function divsAndTheirMultiple(n::Integer)
    primes = eratosphen(n)
    divs = []
    multiples = []
    for d in primes
        if n % d == 0
            push!(divs, d)
            push!(multiples, 0)
            while n%d==0
                n /= d
                multiples[length(multiples)] += 1 
            end
        end
    end
    return primes, multiples
end
