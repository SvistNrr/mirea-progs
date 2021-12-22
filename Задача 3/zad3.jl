function movedraw!(r::Robot, side::HorizonSide)
    while !isborder(r, side)
        putmarker!(r)
        move!(r, side)
    end
    putmarker!(r)
end

inverse(side::HorizonSide) = HorizonSide(mod(Int(side)+2, 4))

function movv(r::Robot, side::HorizonSide, step::Int)
    while !isborder(r, side)
        move!(r, side)
        step += 1
    end
end

function fullfield(r::Robot)
    coordx = 0
    coordy = 0
    stl = HorizonSide(3)
    movv(r, HorizonSide(2), coordy)
    movv(r, HorizonSide(1), coordx)
    while !isborder(r, HorizonSide(0))
        movedraw!(r, stl)
        move!(r, HorizonSide(0))
        stl = inverse(stl)
    movedraw!(r, stl)
    end
end    

    
