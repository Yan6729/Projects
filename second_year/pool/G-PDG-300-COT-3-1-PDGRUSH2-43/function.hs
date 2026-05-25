{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- function
-}

module Functions (
    swap_func,
    swap_l_a_b,
    swapl_aTol_b,
    swapl_bTol_a,
    ra,
    rb,
    rr,
    rra_fct,
    rrb_fct,
    rrr_fct,
) where

-- sa and sb
swap_func :: [Int] -> [Int]
swap_func [x] = [x]
swap_func [] = []
swap_func (x:xs) = (head (take 1 xs)) : x : (drop 1 xs)

-- sc
swap_l_a_b :: [Int] ->  [Int] -> ([Int], [Int])
swap_l_a_b (x:xs) (y:ys) = ((swap_func (x:xs)), (swap_func (y:ys))) 

--pa :  first element from l_b and move it to the first position on the l_a list 
swapl_bTol_a :: [Int] -> [Int] -> ([Int], [Int])
swapl_bTol_a (x: xs) ys = (xs, (x : ys))

--pb : first element from l_a and move it to the first position on the l_b list
swapl_aTol_b :: [Int] -> [Int] -> ([Int], [Int])
swapl_aTol_b xs [] = (xs, [])
swapl_aTol_b xs (y : ys) = ((y : xs), ys)


--ra : shift up all elements of l_a by 1. The first element becomes the last one
ra :: [Int] -> [Int]
ra [] = []
ra (x:xs) = xs ++ [x]

--rb : shift up all elements of l_b by 1. The first element becomes the last one
rb :: [Int] -> [Int]
rb [] = []
rb (x:xs) = xs ++ [x]

--rr : ra and rb at the same time
rr :: [Int] -> [Int] -> ([Int], [Int])
rr xs ys = (ra xs, rb ys)

--rra : rotate l_a toward the end, the last element will become the first.
rra_fct :: [Int] -> [Int]
rra_fct [] = []
rra_fct xs = last xs : init xs

--rrb : rotate l_b toward the end, the last element will become the first.
rrb_fct :: [Int] -> [Int]
rrb_fct [] = []
rrb_fct ys = last ys : init ys

--rrr : rra and rrb at the same time.
rrr_fct :: [Int] -> [Int] -> ([Int], [Int])
rrr_fct xs ys = (rra_fct xs, rrb_fct ys)