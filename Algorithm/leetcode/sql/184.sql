# Write your MySQL query statement below
select d.Name as Department ,t.Name as Employee, t.Salary as Salary 
from Department d 
left join (
    select b.DepartmentId as DepartmentId, b.Salary as Salary, a.Name as Name from (
        select DepartmentId, max(Salary) as Salary from Employee group by DepartmentId
    ) b left join Employee a on a.DepartmentId = b.DepartmentId and b.Salary = a.Salary
) t on d.Id = t.DepartmentId where t.DepartmentId is not null

