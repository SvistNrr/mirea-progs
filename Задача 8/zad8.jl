function zad8(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    shag = 1
    siding = West
    while isborder(r, North)
        go!(r, siding, steps=shag)
        siding = inverse(siding)
        shag += 1
    end
end