#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/CreatorLayer.hpp>
class $modify(CreatorLayer) {
	
	bool init() {

		if (!CreatorLayer::init()) {
			return false;
		};

		auto sprev = CCSprite::createWithSpriteFrameName("GJ_eventBtn_001.png");
		sprev->setScale(0.750f);

		auto sprmap = CCSprite::createWithSpriteFrameName("GJ_mapBtn_001.png");
		sprmap->setScale(0.750f);

		auto sprvers = CCSprite::createWithSpriteFrameName("GJ_versusBtn_001.png");
		sprvers->setScale(0.750f);

		auto eventBtn = CCMenuItemSpriteExtra::create(sprev, this, menu_selector(CreatorLayer::onEventLevel));
		auto mapBtn = CCMenuItemSpriteExtra::create(sprmap, this, menu_selector(CreatorLayer::onAdventureMap));
		auto versusBtn = CCMenuItemSpriteExtra::create(sprvers, this, menu_selector(CreatorLayer::onMultiplayer));

		auto menu = this->getChildByID("creator-buttons-menu");

		const char * ids[3] = {"event-button", "map-button", "versus-button"};
		CCMenuItemSpriteExtra * btns[3] = {eventBtn, mapBtn, versusBtn};
		for (int i = 0; i < 3; i++) {

			auto btn = menu->getChildByID(ids[i]);
			auto evx = btn->getPositionX();
			auto evy = btn->getPositionY();
			btn->removeFromParent();

			auto saidBtn = btns[i];
			saidBtn->setID(ids[i]);
			saidBtn->setPosition({ evx, evy });
			menu->addChild(saidBtn);

		}
		return true;
	}
};