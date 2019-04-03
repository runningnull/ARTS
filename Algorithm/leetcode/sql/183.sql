# select Name as Customers  
# from Customers 
# where Id not in (select distinct CustomerId from Orders)

select Name as Customers  from (
    select Name, CustomerId 
    from Customers c left join Orders o on c.Id = o.CustomerId 
) t where t.CustomerId is null
