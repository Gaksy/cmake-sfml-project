#include "Scene/SelectorScene.h"

extern sf::Texture img_VS;                                       // VS 艺术字图片
extern sf::Texture img_1P;                                       // 1P 文本图片
extern sf::Texture img_2P;                                       // 2P 文本图片

extern sf::Texture img_1P_desc;                                  // 1P 键位描述图片
extern sf::Texture img_2P_desc;                                  // 2P 键位描述图片

extern sf::Texture img_gravestone_left;                          // 朝向左的墓碑图片
extern sf::Texture img_gravestone_right;                         // 朝向右的墓碑图片

extern sf::Texture img_selector_tip;                             // 选角界面提示文本图片
extern sf::Texture img_selector_background;                      // 选角界面背景图片

extern sf::Texture img_1P_selector_btn_idle_left;                // 1P 向左选择按钮默认状态图片
extern sf::Texture img_1P_selector_btn_idle_right;               // 1P 向右选择按钮默认状态图片
extern sf::Texture img_1P_selector_btn_down_left;                // 1P 向左选择按钮按下状态图片
extern sf::Texture img_1P_selector_btn_down_right;               // 1P 向右选择按钮按下状态图片

extern sf::Texture img_2P_selector_btn_idle_left;                // 2P 向左选择按钮默认状态图片
extern sf::Texture img_2P_selector_btn_idle_right;               // 2P 向右选择按钮默认状态图片
extern sf::Texture img_2P_selector_btn_down_left;                // 2P 向左选择按钮按下状态图片
extern sf::Texture img_2P_selector_btn_down_right;               // 2P 向右选择按钮按下状态图片

extern sf::Texture img_peashooter_selector_background_left;      // 选角界面朝向左的婉逗射手背景图片
extern sf::Texture img_peashooter_selector_background_right;     // 选角界面朝向右的婉逗射手背景图片

extern sf::Texture img_sunflower_selector_background_left;       // 选角界面朝向左的龙日葵背景图片
extern sf::Texture img_sunflower_selector_background_right;      // 选角界面朝向右的龙日葵背景图片

SelectorScene::SelectorScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"选角场景"),
    pos_img_VS_({0,0}),
    pos_img_tip_({0,0}),
    pos_img_1P_({0,0}),
    pos_img_2P_({0,0}),
    pos_img_1P_desc_({0,0}),
    pos_img_2P_desc_({0,0}),
    pos_img_1P_name_({0,0}),
    pos_img_2P_name_({0,0}),
    pos_animation_1P({0,0}),
    pos_animation_2P({0,0}),
    pos_img_1P_gravestone({0,0}),
    pos_img_2P_gravestone({0,0}),
    pos_img_1P_selector_btn_left_({0,0}),
    pos_img_1P_selector_btn_right_({0,0}),
    pos_img_2P_selector_btn_left_({0,0}),
    pos_img_2P_selector_btn_right_({0,0})
{ ; }

void SelectorScene::onEnter() {
    printf("进入选角场景\n");
}

void SelectorScene::onExit() {
    printf("退出选角场景\n");
}

void SelectorScene::onUpdate(const size_t delta) {

}

void SelectorScene::onDraw(const Camera& camera) {
    drawSceneLabel();
}

void SelectorScene::onInput(const sf::Event& event) {
    ;
}
