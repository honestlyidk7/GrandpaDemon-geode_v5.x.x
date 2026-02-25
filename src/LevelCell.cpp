#include <Geode/Bindings.hpp>
#include <Geode/modify/LevelCell.hpp>
#include "ListManager.h"
#include "EffectsManager.h"

using namespace geode::prelude;

class $modify(LevelCell) {

    // use m_mainLayer as parent
    void loadCustomLevelCell() {
        LevelCell::loadCustomLevelCell();

        if (ListManager::demonIDList.size() == 0) {
            return;
        }

        if (m_level->m_stars != 10) {
            return;
        }

        int aredlPos = ListManager::getPositionOfID(m_level->m_levelID);
        if (aredlPos == -1 || aredlPos > 499) {
            return;
        }

        CCSprite* originalIcon = nullptr;

        for (unsigned int i = 0; i < m_mainLayer->getChildrenCount(); ++i) {
            if (CCNode* newObj = dynamic_cast<CCNode*>(m_mainLayer->getChildren()->objectAtIndex(i))) {
                if (newObj->getZOrder() == 2) {
                    newObj->setID("grd-demon-icon-layer");
                    for (unsigned int j = 0; j < newObj->getChildrenCount(); ++j) {
                        if (CCSprite* newObj2 = dynamic_cast<CCSprite*>(newObj->getChildren()->objectAtIndex(j))) {
                            if (newObj2->getZOrder() == 3) {
                                originalIcon = newObj2;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (originalIcon == nullptr) {
            return;
        }

        CCSprite* newIcon = ListManager::getSpriteFromPosition(aredlPos, false);
        //CCSprite* newIcon = CCSprite::createWithSpriteFrameName("GrD_demon0.png"_spr);
        auto layer = m_mainLayer->getChildByID("grd-demon-icon-layer");

        auto newPos = originalIcon->getPosition();
        newIcon->setPosition(originalIcon->getPosition());
        newIcon->setZOrder(originalIcon->getZOrder() + 25);

        // ---- SAFE CHILD HANDLING (declare once, reuse) ----
        auto iconChildren = originalIcon->getChildren();

        // Remove any previously moved sprites (tagged 69420)
        if (iconChildren) {
            for (unsigned int i = 0; i < iconChildren->count(); ++i) {
                if (auto spr = dynamic_cast<CCSprite*>(iconChildren->objectAtIndex(i))) {
                    if (spr->getTag() == 69420) {
                        spr->removeFromParentAndCleanup(true);
                    }
                }
            }
        }

        // Copy and reparent children safely
        if (iconChildren && iconChildren->count() > 0) {
            auto childrenCopy = CCArray::create();
            childrenCopy->addObjectsFromArray(iconChildren);

            for (unsigned int i = 0; i < childrenCopy->count(); ++i) {
                if (auto spr = dynamic_cast<CCSprite*>(childrenCopy->objectAtIndex(i))) {
                    spr->setTag(69420);

                    // Safer reparent: detach from originalIcon before adding to layer
                    spr->retain();
                    spr->removeFromParentAndCleanup(false);
                    layer->addChild(spr);
                    spr->setPosition(newPos);
                    spr->release();
                }
            }
        }
        // -----------------------------------------------

        originalIcon->setVisible(false);

        layer->addChild(newIcon);

        if (aredlPos <= 24) {
            EffectsManager::addInfinitySymbol(newIcon->getPosition(), layer, aredlPos);
        }
    }
};