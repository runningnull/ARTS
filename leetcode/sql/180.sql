select distinct Num as ConsecutiveNums 
from Logs a 
where 
(
    select count(1) from Logs b where b.Id >= a.Id and b.Id < a.Id+3 and b.Num = a.Num
) = 3