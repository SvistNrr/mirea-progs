function zad14(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    ras_West = go_to_border_come_back_and_return_distance!(r, West, go_around_barriers=true)
    ras_East = go_to_border_come_back_and_return_distance!(r, East, go_around_barriers=true)
    ras_North = go_to_border_come_back_and_return_distance!(r, North, go_around_barriers=true)
    ras_South = go_to_border_come_back_and_return_distance!(r, South, go_around_barriers=true)
    go!(r, North, steps=ras_North, go_around_barriers=true, markers=true)
    go!(r, South, steps=ras_North, go_around_barriers=true)

    go!(r, West, steps=ras_West, go_around_barriers=true, markers=true)
    go!(r, East, steps=ras_West, go_around_barriers=true, markers=true)

    go!(r, East, steps=ras_East, go_around_barriers=true, markers=true)
    go!(r, West, steps=ras_East, go_around_barriers=true, markers=true)

    go!(r, South, steps=ras_South, go_around_barriers=true, markers=true)
    go!(r, North, steps=ras_South, go_around_barriers=true, markers=true)
end