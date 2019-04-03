# select distinct a.Email as Email from Person a, Person b where a.Email = b.Email and a.Id < b.Id;
select Email from Person group by Email having count(Email) > 1;