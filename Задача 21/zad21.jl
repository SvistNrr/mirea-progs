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

function zad21(r::Robot)
    North = HorizonSide(0)
    South = HorizonSide(2)
    West = HorizonSide(1)
    East = HorizonSide(3)
    backpath = go_to_some_corner_and_return_path!(r, South, West, go_around_barriers=true)
    m_hor = 0
    n_hor = false
    m_vert = 0
    n_vert = false
    side = East

    while !isborder(r, North)
        while move_if_possible!(r, side)
            m_hor, n_hor = find_border!(r, m_hor, n_hor, North)
            m_vert, n_vert = find_border!(r, m_vert, n_vert, West)
        end
        m_hor, n_hor = find_border!(r, m_hor, n_hor, North)
        m_vert, n_vert = find_border!(r, m_vert, n_vert, West)
        side = inverse_side(side)
        move!(r, North)
    end
    println(m_hor)
    println(m_vert)
end
