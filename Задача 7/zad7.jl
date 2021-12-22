function lever(m::Int64)
    if m == 1
        return 0
    else
        return 1
    end
end

function kraska(r::Robot, m::Int64)
    if m == 1
        putmarker!(r)
    end
end

function chess(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    m = 0
    sch = -1
    k = 1
    if go_to_border_come_back_and_return_distance!(r, North) == go_to_border_come_back_and_return_distance!(r, West)
        m = 1
        k = 0
    end
    backpath = go_to_some_corner_and_return_path!(r, North, West)
    length = go_to_border_come_back_and_return_distance!(r, East)
    weight = go_to_border_come_back_and_return_distance!(r, South)
    while sch != weight
        while !isborder(r, East)
            kraska(r, m)
            m = lever(m)
            move!(r, East)
        end
        if k == 1
            putmarker!(r)
        end
        go!(r, West, steps = length)
        go!(r, South, steps = 1)
        m = k
        k = lever(k)
        sch += 1
    end
    go!(r, West, steps = length)
    go!(r, North, steps = weight)
    go_by_path!(r, backpath)
end
    

