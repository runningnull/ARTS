select t.Score, 
(select count(distinct Score)+1 from Scores where Score > t.Score) as Rank
from Scores t order by t.Score desc;
