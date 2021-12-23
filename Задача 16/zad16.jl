function fullfield(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    xcoord = go_to_border_come_back_and_return_distance!(r, South, go_around_barriers=true)
    ycoord = go_to_border_come_back_and_return_distance!(r, West, go_around_barriers=true)
    begin_path = go_to_some_corner_and_return_path!(r, South, West, go_around_barriers=true)
    b = 0
    length = go_to_border_come_back_and_return_distance!(r, East)
    weight = go_to_border_come_back_and_return_distance!(r, North)
    while b != weight
        go!(r, East, steps=length, go_around_barriers=true, markers=true)
        go!(r, West, steps=length, go_around_barriers=true, markers=true)
        move!(r, North)
        b += 1
    end
    go!(r, East, steps=length, go_around_barriers=true, markers=true)
    go!(r, West, steps=length, go_around_barriers=true)
    go!(r, South, steps=weight, go_around_barriers=true)

    go!(r, East, steps=xcoord, go_around_barriers=true)
    go!(r, North, steps=ycoord, go_around_barriers=true)
end
