function find_border!(r::Robot, m::Int, n::Bool, side::HorizonSide)
    if isborder(r, side)
        n = true
    end
    if !isborder(r, side) && n
        n = false
        m += 1
    end
    return m, n
end

function zad20(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    backpath = go_to_some_corner_and_return_path!(r, South, West, go_around_barriers=true)
    m = 0
    a = 0
    n = false
    side = East
    weight = go_to_border_come_back_and_return_distance!(r, East, go_around_barriers=true)
    length = go_to_border_come_back_and_return_distance!(r, East, go_around_barriers=true)
    while a != weight
        while !isborder(r, side)
            m, n = find_border!(r, m, n, North)
            move!(r,side)
        end
        m, n = find_border!(r, m, n, North)
        go!(r, inverse_side(side), steps=length)
        go!(r, North, go_around_barriers=true)
        a += 1
    end
    println(m)
end
