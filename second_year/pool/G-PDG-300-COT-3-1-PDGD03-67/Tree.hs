{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- Tree
-}

data Tree a = Empty
    | Node (Tree a) a (Tree a)

instance Show a => Show (Tree a) where
  show Empty = "Empty"
  show (Node Empty value Empty) = 
        "Node Empty " ++ show value ++
           " Empty"
  show (Node left value right) =
    "Node (" ++ show left ++ ") "
           ++ show value ++
           " (" ++ show right ++ ")"

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = (Node Empty value Empty) 
addInTree value (Node left a right)
    | value == a = (Node left a right)
    | value < a = (Node (addInTree value left) a right)
    | value > a = (Node left a (addInTree value right))
