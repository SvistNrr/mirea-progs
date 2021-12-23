function zad1(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    ras_West = go_to_border_come_back_and_return_distance!(r, West)
    ras_East = go_to_border_come_back_and_return_distance!(r, East)
    ras_North = go_to_border_come_back_and_return_distance!(r, North)
    ras_South = go_to_border_come_back_and_return_distance!(r, South)
    go!(r, North, steps=ras_North, markers=true)
    go!(r, South, steps=ras_North, markers=true)

    go!(r, West, steps=ras_West,  markers=true)
    go!(r, East, steps=ras_West,  markers=true)

    go!(r, East, steps=ras_East,  markers=true)
    go!(r, West, steps=ras_East,  markers=true)

    go!(r, South, steps=ras_South,  markers=true)
    go!(r, North, steps=ras_South,  markers=true)
end