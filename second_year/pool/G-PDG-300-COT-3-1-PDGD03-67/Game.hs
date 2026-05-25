{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- Game
-}


class HasItem a where
    getItem :: a -> Maybe Item

    hasItem :: a -> Bool
    hasItem object = case getItem object of
        Just _ -> True
        Nothing -> False

data Item = Sword | Bow | MagicWand
    deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton (Item) | Witch (Maybe Item)
    deriving (Eq)

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch maybeitem) = maybeitem


createMummy :: Mob -- a Mummy
createMummy = Mummy

createArcher :: Mob -- a Skeleton holding a Bow
createArcher = Skeleton Bow

createKnight :: Mob -- a Skeleton holding a Sword
createKnight = Skeleton Sword

createWitch :: Mob -- a Witch holding Nothing
createWitch = Witch Nothing

createSorceress :: Mob -- a Witch holding a MagicWand
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create str = case str of
    "mummy" -> Just createMummy
    "doomed archer" -> Just createArcher
    "dead knight" -> Just createKnight
    "witch" -> Just createWitch
    "sorceress" -> Just createSorceress
    _ -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip arm (Skeleton _) = Just (Skeleton arm)
equip arm (Witch _) = Just (Witch (Just arm))
