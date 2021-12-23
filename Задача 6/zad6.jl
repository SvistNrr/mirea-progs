function signal(r::Robot, l::Int64)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    for i in 1:l
        if isborder(r, North)
            return 0
            break
        end
        move!(r, East)
    end
    return 1
end

function change_side(k::Int64)
    if k == 0
        return 1
    end
    return 0
end

function sides_of_rectangle(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    a = 0
    b = 0
    while isborder(r, North)
        a += 1
        move!(r, East)
    end
    go!(r, West, steps=a+1)
    move!(r, North)
    while isborder(r, East)
        b += 1
        move!(r, North)
    end
    go!(r, South, steps=b+1)
    move!(r, East)
    return [a, b]
end
        
function zad6(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    backpath = go_to_some_corner_and_return_path!(r, North, West, go_around_barriers=true)
    length = go_to_border_come_back_and_return_distance!(r, East, go_around_barriers=true)
    weight = go_to_border_come_back_and_return_distance!(r, South, go_around_barriers=true)
    k = true
    while k
        if signal(r, length) == 0
            break
        end
        go!(r, West, steps=length)
    end
    rect = sides_of_rectangle(r::Robot)
    move!(r, West)
    k = 0
    for side in (East, North, West, South)
        go!(r, side, steps=rect[k]+1, markers=true)
        k = change_side(k)
        side = antinextside(side)
    end
end