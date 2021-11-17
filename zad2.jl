function movedraw!(r::Robot, side::HorizonSide)
    while !isborder(r, side)
        putmarker!(r)
        move!(r, side)
    end
end

function movv(r::Robot, side::HorizonSide, step::Int)
    for i in step
        move!(r, side)
    end
end

function square(r)
    sides = [3, 0, 1, 2]
    coordx = 1
    coordy = 1
    while !isborder(r, HorizonSide(2))
        move!(r, HorizonSide(2))
        coordx += 1
    end
    while !isborder(r, HorizonSide(1))
        move!(r, HorizonSide(1))
        coordy += 1
    end
    println(coordx)
    println(coordy)
    for i in sides
        movedraw!(r, HorizonSide(i))
    end
    movv(r, HorizonSide(3), coordx)
    movv(r, HorizonSide(0), coordy)
end