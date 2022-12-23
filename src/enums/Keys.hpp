#ifndef KEYS_ENUM
#define KEYS_ENUM


/**
 * @brief состояние клавиши
 *  создавался изначально для плавного движения в нескольких направлениях разом
 *  у sfml проблемки какие-то с потоком событий 
 * 
 */
enum KeyCondition {
    PRESSED,
    RELEASED,
};



#endif // KEYS_ENUM