#ifndef SECECTORSCENE_H
#define SECECTORSCENE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scene/Scene.h"
#include "ResourcesUnit/Animation.h"


class SelectorScene: public Scene {
public:
    explicit SelectorScene(const sf::Font& font);
    explicit SelectorScene();
    ~SelectorScene() override=default;

public:
    void onEnter()override;
    void onExit()override;
    void onUpdate(size_t delta)override;
    void onDraw(const Camera& camera)override;
    void onInput(const sf::Event& event)override;

private:
    enum class PlayerType {
        Peashooter = 0,
        Sunflower = 1,
        Invalid = 2
    };

private:
    sf::Vector2f pos_img_VS_;                                       // VS 艺术字图片
    sf::Vector2f pos_img_tip_;                                      // 提示信息文本图片位置
    sf::Vector2f pos_img_1P_;                                       // 1P 文本图片
    sf::Vector2f pos_img_2P_;                                       // 2P 文本图片
    sf::Vector2f pos_img_1P_desc_;                                  // 1P 键位描述图片
    sf::Vector2f pos_img_2P_desc_;                                  // 2P 键位描述图片
    sf::Vector2f pos_img_1P_name_;                                  // 1P 角色姓名文本位置
    sf::Vector2f pos_img_2P_name_;                                  // 2P 角色姓名文本位置
    sf::Vector2f pos_animation_1P;                                  // 1P 角色动画位置
    sf::Vector2f pos_animation_2P;                                  // 2P 角色动画位置
    sf::Vector2f pos_img_1P_gravestone_;                             // 1P 墓碑图片位置
    sf::Vector2f pos_img_2P_gravestone_;                             // 2P 墓碑图片位置
    sf::Vector2f pos_img_1P_selector_btn_left_;                     // 1P 向左切换按钮位置
    sf::Vector2f pos_img_1P_selector_btn_right_;                    // 1P 向右切换按钮位置
    sf::Vector2f pos_img_2P_selector_btn_left_;                     // 2P 向左切换按钮位置
    sf::Vector2f pos_img_2P_selector_btn_right_;                    // 2P 向右切换按钮位置

    Animation animation_peashooter;                                 // 豌豆射手动画
    Animation animation_sunflower;                                  // 龙日葵动画

    PlayerType player_type_1;
    PlayerType player_type_2;

    sf::Text str_peashooter_name_;
    sf::Text str_sunflower_name_;

    float selector_background_scroll_offset_x_;

    bool is_btn_1P_left_down = false;
    bool is_btn_1P_right_down = false;
    bool is_btn_2P_left_down = false;
    bool is_btn_2P_right_down = false;
};

#endif //SECECTORSCENE_H
