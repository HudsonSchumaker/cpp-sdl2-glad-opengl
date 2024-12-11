/**
* @file EntityManager.cpp
* @author Hudson Schumaker
* @brief Implements the EntityManager class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "EntityManager.hpp"

EntityManager::~EntityManager() {
	clear();
}

EntityManager* EntityManager::getInstance() {
	if (instance == nullptr) {
		instance = new EntityManager();
	}

	return instance;
}

Entity* EntityManager::createEntity() {
	return createEntity(0.0f, 0.0f, 0.0f);
}

Entity* EntityManager::createEntity(const float x, const float y, const float z) {
	Entity* entity = new Entity(++index, x, y, z);
	entities.push_back(entity);
	return entity;
}

Entity* EntityManager::createEntity(const float x, const float y, const float z, Tag tag) {
	auto entity = createEntity(x, y, z);
	entity->tags.first = tag;

	if (tag == Tag::PLAYER) {
		playerId = entity->id;
	}

	return entity;
}

Entity* EntityManager::getEntity(const unsigned long id) {
	unsigned long low = 0;
	unsigned long high = static_cast<unsigned long>(entities.size() - 1);

	// search using binary search
	while (low <= high) {
		unsigned long mid = (low + high) / 2;

		if (entities[mid]->id == id) {
			return entities[mid];
		}
		else if (entities[mid]->id < id) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return nullptr;
}

void EntityManager::removeEntity(Entity* entity) {
	auto it = std::find(entities.begin(), entities.end(), entity);
	if (it != entities.end()) {
		delete entity;
		entities.erase(it);
	}
}

void EntityManager::update() {
	for (auto& e : entitiesToBeKilled) {
		removeEntity(e);
	}
	entitiesToBeKilled.clear();
	std::sort(entities.begin(), entities.end(), compareAsc);
}

void EntityManager::killEntity(Entity* entity) {
	entitiesToBeKilled.insert(entity);
}

const std::vector<Entity*>& EntityManager::getEntities() const {
	return entities;
}

std::vector<Entity*> EntityManager::getEntitiesWithTag(Tag tag) {
	std::vector<Entity*> list;
	for (auto& e : entities) {
		if (e->tags.first == tag) {
			list.push_back(e);
		}
	}
	return list;
}

std::vector<Entity*> EntityManager::getEntitiesWithLayer(Layer layer) {
	std::vector<Entity*> list;
	for (auto& e : entities) {
		if (e->layer == layer) {
			list.push_back(e);
		}
	}
	return list;
}

bool EntityManager::compareAsc(const Entity* e1, const Entity* e2) {
	return (e1->id < e2->id); // For the binary search, when searching an Entity by id.
}

void EntityManager::clear() {
	for (auto& e : entities) {
		delete e;
	}
	entities.clear();
	index = 0;
}

void EntityManager::clear(Entity* entity) {
	auto it = std::find(entities.begin(), entities.end(), entity);
	if (it != entities.end()) {
		delete* it;
		entities.erase(it);
	}
}

long int EntityManager::getPlayerId() const {
	return playerId;
}
