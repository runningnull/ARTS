# Write your MySQL query statement below
select 
    t.Request_at as Day,
    convert(count(if(t.Status<>'completed', 1, null)) / count(t.Status), decimal(15,2)) as Cancellation Rate
from Trips t 
left join Users c on t.Client_Id = c.Users_Id 
left join Users d on t.Driver_Id = d.Users_Id 
where 
    d.Banned = 'No' and 
    c.Banned = 'No' and 
    t.Request_at between '2013-10-01' and '2013-10-03' 
group by Request_at
