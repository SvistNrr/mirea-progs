function zad10(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    summa = 0
    amount_of_markers = 0
    a = 0
    b = -1
    length = go_to_border_come_back_and_return_distance!(r, East)
    weight = go_to_border_come_back_and_return_distance!(r, North)
    while b != weight
        while a != length
            if ismarker(r)
                summa += temperature(r)
                amount_of_markers += 1  
            end
            move!(r, East)
            a += 1
        end
        a = 0
        if ismarker(r)
            summa += temperature(r)
            amount_of_markers += 1
        end
        go!(r, West, steps=length)
        go!(r, North, steps=1)
        b += 1
    end
    println(amount_of_markers)
    return (summa / amount_of_markers )
end