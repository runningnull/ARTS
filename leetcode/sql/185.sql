# Write your MySQL query statement below
select 
    d.Name as Department,
    e.Name as Employee, 
    e.Salary as Salary 
from Employee e, Department d 
where e.DepartmentId = d.Id 
and (
    select count(distinct Salary) 
    from Employee t 
    where 
    t.DepartmentId = e.DepartmentId and 
    t.Id <> e.Id and 
    t.Salary > e.Salary
) < 3 
order by DepartmentId, Salary desc