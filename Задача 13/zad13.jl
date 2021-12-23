function kosoy_x(r::Robot)
    North=HorizonSide(0)
    West=HorizonSide(1)
    South=HorizonSide(0)
    East=HorizonSide(1)

    for side in ((North,East),(South,East),(South,West),(North,West))
        mark!(r,side)
        markmove!(r,inverse_kosoy_krest(side))
    end
    putmarker!(r)
end

function mark!(r::Robot, side::NTuple{2,HorizonSide})
     while isborder(r,side) == false
         move!(r,side)
     end
end

function isborder(r::Robot, side::NTuple{2,HorizonSide})
     return isborder(r, side[1]) || isborder(r, side[2])
end

function HorizonSideRobots.move!(r::Robot, side::NTuple{2,HorizonSide}) 
     for i in side
         move!(r,i)
     end
end


function markmove!(r::Robot,side::NTuple{2,HorizonSide})
     while ismarker(r)
         move!(r,side)
     end
end

inverse_kosoy_krest(side::NTuple{2,HorizonSide}) = (inverse_side(side[1]), inverse_side(side[2]))