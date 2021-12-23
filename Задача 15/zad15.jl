function zad15(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    xcoord = go_to_border_come_back_and_return_distance!(r, South, go_around_barriers=true)
    ycoord = go_to_border_come_back_and_return_distance!(r, West, go_around_barriers=true)
    begin_path = go_to_some_corner_and_return_path!(r, South, West, go_around_barriers=true)
    side = HorizonSide(3)
    length = go_to_border_come_back_and_return_distance!(r, East, go_around_barriers=true)
    weight = go_to_border_come_back_and_return_distance!(r, North, go_around_barriers=true)
    for i in 1:4
        if (side == HorizonSide(1)) || (side == HorizonSide(3))
            go!(r, side, steps=length, go_around_barriers=true, markers=true)
        elseif (side == HorizonSide(0)) || (side == HorizonSide(2))
            go!(r, side, steps=weight, go_around_barriers=true , markers=true)
        end
        side = antinextside(side)
    end
    go!(r, East, steps=xcoord, go_around_barriers=true)
    go!(r, North, steps=ycoord, go_around_barriers=true,)

end

