function f10(r::Robot)
    Nord=HorizonSide(0)
    Ost=HorizonSide(3)
    West=HorizonSide(1)
    Sud=HorizonSide(2)
    backpath = moving_in_angle!(r)
    weight = weight(r)
    height = height(r)
    temperatures = 0
    markers_amount = 0
    for i in in 1:height
        for j in 1:weight
            if ismarker(r)
                temperatures += temperature(r)
                markers_amount += 1
            end
            move!(r, Ost)
        end
        if !isborder(r, Nord)
            move!(r, Nord)
            moving_defsteps!(r, West, weight)
        end
    end
    println(temperatures)
    println(markers_amount)
    println(temperatures / markers_amount)
end
    


