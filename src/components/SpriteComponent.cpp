#include "SpriteComponent.h"
#include "../actors/Actor.h"
#include "../Game.h"
#include "../Global.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder) : Component(owner),
                                                                texture(nullptr),
                                                                sourceRect(nullptr),
                                                                drawOrder(drawOrder),
                                                                width(CELL_SIZE),
                                                                height(CELL_SIZE)
{ ((Game*)owner->getGame())->addSprite(this); }

SpriteComponent::~SpriteComponent() { owner->getGame()->removeSprite(this); }

void SpriteComponent::draw(SDL_Renderer* renderer){
    if(texture) {
        SDL_Rect rect = {
            static_cast<int>(this->owner->getPosition().x),
            static_cast<int>(this->owner->getPosition().y),
            static_cast<int>(this->width),
            static_cast<int>(this->height)
        };

        SDL_RenderCopy(renderer, this->texture, this->sourceRect, &rect);
    }
}