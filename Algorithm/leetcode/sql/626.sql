select 
    id, 
    (
        if(
            mod(s.id, 2)=0,
            (select student from seat where id = s.id-1), 
            if(
                s.id+1<=(select max(id) from seat), 
                (select student from seat where id = s.id+1),
                s.student
            )
        )
    ) as student 
from seat s