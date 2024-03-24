#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/CreatorLayer.hpp>
class $modify(CreatorLayer) {
	
	bool init() {

		if (!CreatorLayer::init()) {
			return false;
		};

		auto sprev = CCSprite::createWithSpriteFrameName("GJ_eventBtn_001.png");
		sprev->setScale(.75f);

		auto sprmap = CCSprite::createWithSpriteFrameName("GJ_mapBtn_001.png");
		sprmap->setScale(.75f);

		auto sprvers = CCSprite::createWithSpriteFrameName("GJ_versusBtn_001.png");
		sprvers->setScale(.75f);

		auto menu = this->getChildByID("creator-buttons-menu");

		std::map<std::string, CCMenuItemSpriteExtra*> idsToBtns = {
			{ "event-button", CCMenuItemSpriteExtra::create(sprev, this, menu_selector(CreatorLayer::onEventLevel)) },
			{ "map-button", CCMenuItemSpriteExtra::create(sprmap, this, menu_selector(CreatorLayer::onAdventureMap)) },
			{ "versus-button", CCMenuItemSpriteExtra::create(sprvers, this, menu_selector(CreatorLayer::onMultiplayer)) }
		};
		
		for (auto pair = idsToBtns.begin(); pair != idsToBtns.end(); pair++) {
			auto id = pair->first.c_str();
			auto superExpertLoaded = ((strcmp("versus-button", id) == 0) && (Loader::get()->isModLoaded("xanii.super_expert")));

			if (!menu->getChildByID(id)) continue; // avoid crash if child not found

			auto btn = menu->getChildByID(id);
			auto evx = btn->getPositionX();
			auto evy = btn->getPositionY();

			if (!superExpertLoaded) {
				btn->removeFromParent();
			}

			auto saidBtn = pair->second;
			saidBtn->setID(id);
			saidBtn->setPosition({ evx, evy });

			if (!superExpertLoaded) {
				menu->addChild(saidBtn);
			};
		}
		return true;
	}
};