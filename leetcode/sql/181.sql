# select Name as Employee 
# from Employee t 
# where t.ManagerId is not null and t.Salary > ( 
#     select e.Salary 
#     from Employee e 
#     where e.Id = t.ManagerId
# )
select a.Name as Employee from Employee a, Employee b where a.ManagerId = b.Id and a.Salary > b.Salary