function stairs(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    xcoord = go_to_border_come_back_and_return_distance!(r, South, go_around_barriers=true)
    ycoord = go_to_border_come_back_and_return_distance!(r, West, go_around_barriers=true)
    begin_path = go_to_some_corner_and_return_path!(r, South, West)
    amount = 0
    length = go_to_border_come_back_and_return_distance!(r, East)
    while (!isborder(r, North)) & (length != 0)
        if length == 0
            putmarker!(r)
        else
            go!(r, East, steps=length, go_around_barriers=true, markers=true)
            go!(r, West, steps=length, go_around_barriers=true, markers=true)
        end
        length -= 1
        move!(r, North)
    end
    go!(r, East, steps=length, go_around_barriers=true, markers=true)
    go!(r, West, steps=length, go_around_barriers=true)
    move_to_border(r, South)
    go!(r, East, steps=xcoord, go_around_barriers=true, markers=true)
    go!(r, North, steps=ycoord, go_around_barriers=true, markers=true)
end