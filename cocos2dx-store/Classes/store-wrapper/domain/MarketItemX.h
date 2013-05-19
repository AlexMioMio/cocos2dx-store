//
// Created by Fedor Shubin on 5/19/13.
//



#ifndef __MarketItemX_H_
#define __MarketItemX_H_

#include "cocos2d.h"
#include "SoomlaMacros.h"
#include "JSONConstsX.h"


namespace soomla {
    class MarketItem: public cocos2d::CCObject {
        enum Consumable {
            NONCONSUMABLE,
            CONSUMABLE,
            SUBSCRIPTION,
        };
        SL_SYNTHESIZE_RETAIN_WITH_DICT(cocos2d::CCString *, mProductId, ProductId, JSON_MARKETITEM_PRODUCT_ID);
        SL_SYNTHESIZE_RETAIN_WITH_DICT(cocos2d::CCInteger *, mConsumable, Consumable, JSON_MARKETITEM_CONSUMABLE);
        SL_SYNTHESIZE_RETAIN_WITH_DICT(cocos2d::CCDouble *, mPrice, Price, JSON_MARKETITEM_PRICE);
    public:
        MarketItem(): mProductId(NULL), mConsumable(NULL), mPrice(NULL) {};

        static MarketItem *create(cocos2d::CCString *productId, cocos2d::CCInteger *consumable, cocos2d::CCDouble * price);
        static MarketItem *createWithDictionary(cocos2d::CCDictionary* dict);

        bool init(cocos2d::CCString *productId, cocos2d::CCInteger *consumable, cocos2d::CCDouble * price);
        virtual bool initWithDictionary(cocos2d::CCDictionary* dict);

        virtual ~MarketItem();

        virtual cocos2d::CCDictionary* toDictionary();
    };
};


#endif //__MarketItemX_H_
