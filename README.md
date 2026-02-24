# GrandpaDemon (Unofficial Geode v5 + AREDL v2 Fix)

Unofficial compatibility patch/fork of **GrandpaDemon** by **ItzKiba**.

This fork updates the mod to work with newer versions of **Geode (v5)** and fixes AREDL API fetching by migrating from the old deprecated endpoint to the current **AREDL v2 API**.

## Credits

- **Original mod:** [ItzKiba / GrandpaDemon](https://github.com/ItzKiba/GrandpaDemon)
- This repo is an **unofficial update patch** for compatibility and API changes.

## What this fixes

### Geode v5 compatibility
- Migrates web request handling to Geode v5 async API (`TaskHolder<web::WebResponse>`)
- Replaces deprecated `CCARRAY_FOREACH` usage
- Updates build settings for Geode v5 / C++23

### AREDL API fixes
- Updates the old AREDL endpoint to the current **v2** endpoint
- Updates parsing logic from legacy `_id` to `level_id`

### Stability / safety
- Adds a safe fallback return in `getSpriteFromPosition(...)` to avoid undefined behavior

## Tested On

- **Geometry Dash:** `2.2081`
- **Geode:** `5.0.1`

# Grandpa Demon
A mod created by ItzKiba.

![Title](resources/readme/difficulties.png)

## Overview
The humble Extreme Demon is the highest difficulty in all of Geometry Dash. **However, there is no possible way that Acheron and ACU should be considered the same difficulty.** Think that there should be more demon difficulties above Extreme? Look no further than the **Grandpa Demon mod!**

## Features
* *Up to 6 new demon difficulties* above Extreme Demon!
* *All Rated Extremes Demon List* integration for choosing the demon difficulties.
* *2.2 List support!*
* ***Grandpa Demon!***


**Additionally, the highest demon difficulties each have their own **animated backgrounds** and **particles** for the level page!*

![Demons](resources/readme/demons.png)

## New Demon Difficulties
The difficulties of extreme demons are chosen based on their positions on the [AREDL](https://aredl.pages.dev/#/).

* Top 500 Demons - *Supreme Demon*
* Top 250 Demons - *Ultimate Demon*
* Top 150 Demons - *Legendary Demon*
* Top 75 Demons - *Mythical Demon*
* Top 25 Demons - *Infinite Demon*
* Top 1 Demon - *Grandpa Demon*

***Note:** Grandpa Demon is optional and can be disabled in the mod's settings.*

## Credits
* **tcoffa** for creating the original Grandpa Demon sprite
* **Geode's Discord** for answering my stupid questions
* **AeonAir** for making me do this out of spite in the first place
