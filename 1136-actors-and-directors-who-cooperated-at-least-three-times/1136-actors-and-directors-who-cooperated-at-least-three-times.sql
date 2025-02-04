# Write your MySQL query statement below
select actor_id, director_id from
    (select actor_id, director_id, count(timestamp) as ct
        from ActorDirector group by actor_id, director_id
    ) as table1
where ct>=3;