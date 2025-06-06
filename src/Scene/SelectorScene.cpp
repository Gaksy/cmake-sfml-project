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

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

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
    pos_img_1P_gravestone_({0,0}),
    pos_img_2P_gravestone_({0,0}),
    pos_img_1P_selector_btn_left_({0,0}),
    pos_img_1P_selector_btn_right_({0,0}),
    pos_img_2P_selector_btn_left_({0,0}),
    pos_img_2P_selector_btn_right_({0,0}),
    animation_peashooter(p_window),
    animation_sunflower(p_window)
{ ; }

void SelectorScene::onEnter() {
    animation_peashooter.setAtlas(&atlas_peashooter_idle_right);
    animation_sunflower.setAtlas(&atlas_sunflower_idle_right);
    animation_peashooter.setInterval(100);
    animation_sunflower.setInterval(100);

    static constexpr int OFFSET_X = 50;

    const unsigned int width = getWindowWidth();
    const unsigned int height = getWindowHeight();

    pos_img_VS_.x = (width - img_VS.getSize() .x) / 2;
    pos_img_VS_.y = (height - img_VS.getSize().y) / 2;
    pos_img_tip_.x = (width - img_selector_tip.getSize().x) / 2;
    pos_img_tip_.y = height - 125;
    pos_img_1P_.x = (width / 2 - img_1P.getSize().x) / 2 - OFFSET_X;
    pos_img_1P_.y = 35;
    pos_img_2P_.x = width / 2 + (width / 2 - img_2P.getSize().x) / 2 + OFFSET_X;
    pos_img_2P_.y = pos_img_1P_.y;
    pos_img_1P_desc_.x = (width / 2 - img_1P_desc.getSize().x) / 2 - OFFSET_X;
    pos_img_1P_desc_.y = height - 150;
    pos_img_2P_desc_.x = width / 2 + (width / 2 - img_2P_desc.getSize().x) / 2 + OFFSET_X;
    pos_img_2P_desc_.y = pos_img_1P_desc_.y;
    pos_img_1P_gravestone_.x = (width / 2 - img_gravestone_right.getSize().x) / 2 - OFFSET_X;
    pos_img_1P_gravestone_.y = pos_img_1P_.y + img_1P.getSize().y + 35;
    pos_img_2P_gravestone_.x = width / 2 + (width / 2 - img_gravestone_left.getSize().x) / 2 + OFFSET_X;
    pos_img_2P_gravestone_.y = pos_img_1P_gravestone_.y;
    pos_animation_1P.x = (width / 2 - atlas_peashooter_idle_right.getFrameImage(0)->getSize().x) / 2 - OFFSET_X;
    pos_animation_1P.y = pos_img_1P_gravestone_.y + 80;
    pos_animation_2P.x = width / 2 + (width / 2 - atlas_peashooter_idle_right.getFrameImage(0)->getSize().x) / 2 + OFFSET_X;
    pos_animation_2P.y = pos_animation_1P.y;
    pos_img_1P_name_.y = pos_animation_1P.y + 155;
    pos_img_2P_name_.y = pos_img_1P_name_.y;
    pos_img_1P_selector_btn_left_.x = pos_img_1P_gravestone_.x - img_1P_selector_btn_idle_left.getSize().x;
    pos_img_1P_selector_btn_left_.y = pos_img_1P_gravestone_.y + (img_gravestone_right.getSize().y - img_1P_selector_btn_idle_left.getSize().y) / 2;
    pos_img_1P_selector_btn_right_.x = pos_img_1P_gravestone_.x + img_gravestone_right.getSize().x;
    pos_img_1P_selector_btn_right_.y = pos_img_1P_selector_btn_left_.y;
    pos_img_2P_selector_btn_left_.x = pos_img_2P_gravestone_.x - img_2P_selector_btn_idle_left.getSize().x;
    pos_img_2P_selector_btn_left_.y = pos_img_1P_selector_btn_left_.y;
    pos_img_2P_selector_btn_right_.x = pos_img_2P_gravestone_.x + img_gravestone_left.getSize().x;
    pos_img_2P_selector_btn_right_.y = pos_img_1P_selector_btn_left_.y;
}

void SelectorScene::onExit() {
    printf("退出选角场景\n");
}

void SelectorScene::onUpdate(const size_t delta) {

}

void SelectorScene::onDraw(const Camera& camera) {
    drawTexture({0,0}, img_selector_background);
    drawTexture(pos_img_VS_, img_VS);
    drawTexture(pos_img_1P_, img_1P);
    drawTexture(pos_img_2P_, img_2P);
    drawTexture(pos_img_1P_gravestone_, img_gravestone_right);
    drawTexture(pos_img_2P_gravestone_, img_gravestone_left);
    drawTexture(pos_img_1P_desc_, img_1P_desc);
    drawTexture(pos_img_2P_desc_, img_2P_desc);
    drawTexture(pos_img_tip_, img_selector_tip);
    drawSceneLabel();
}

void SelectorScene::onInput(const sf::Event& event) {

}
