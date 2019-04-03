select a.Id 
from Weather a join Weather b on datediff(b.RecordDate, a.RecordDate) = -1
and a.Temperature > b.Temperature  