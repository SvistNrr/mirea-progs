function check_mark!(r::Robot, side::HorizonSide, n::Int64)
    for i in 1:n
        if ismarker(r)
            return nothing
        end
        go!(r, side, go_around_barriers=true)
    end
end

function zad19(r::Robot)
    step = 1
    side = West
    while !ismarker(r)
        for i in 1:2
            check_mark!(r, side, step)
            side = nextside(side)
        end
        step += 1
    end
end
