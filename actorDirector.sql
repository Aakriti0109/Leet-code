-- Actors and Directors who Cooperated At Least 3 Times
select actor_id, director_id from ActorDirector
group by actor_id, director_id
having count(*)>=3;