#include "Scene/GameScene.h"

#include <vector>
#include "Util/Platform.h"
#include "Scene/SceneManager.h"

extern sf::Texture img_sky;                  // 天空图片
extern sf::Texture img_hills;                // 山脉图片
extern sf::Texture img_platform_large;       // 大型平台图片
extern sf::Texture img_platform_small;       // 小型平台图片

extern bool is_debug;

extern std::vector<Platform> platform_list;

extern SceneManager game_scene_manager;
extern Camera main_camera;

GameScene::GameScene(const sf::Font& font, sf::RenderWindow* p_window):
    Scene(font, p_window, L"游戏局内场景")
{ ; }

GameScene::GameScene(sf::RenderWindow* p_window):
    Scene(p_window, L"游戏局内场景")
{ ; }

GameScene::~GameScene() {
    Scene::~Scene();
}

void GameScene::onEnter() {
    const unsigned int width = getWindowWidth();
    const unsigned int height = getWindowHeight();

    pos_img_sky_.x = (static_cast<float>(width) - static_cast<float>(img_sky.getSize().x)) / 2.0f;
    pos_img_sky_.y = (static_cast<float>(height) - static_cast<float>(img_sky.getSize().y)) / 2.0f;

    pos_img_hills_.x = (static_cast<float>(width) - static_cast<float>(img_hills.getSize().x)) / 2.0f;
    pos_img_hills_.y = (static_cast<float>(height) - static_cast<float>(img_hills.getSize().y)) / 2.0f;

    platform_list.resize(4);

    // 大型平台
    Platform& large_platform = platform_list[0];
    large_platform.setTexture(&img_platform_large);
    large_platform.setRenderPosition({122, 455});
    large_platform.setShape({
        static_cast<float>(large_platform.getRenderPosition().y) + 60.0f,
        static_cast<float>(large_platform.getRenderPosition().x) + 30.0f,
        static_cast<float>(large_platform.getRenderPosition().x) + static_cast<float>(img_platform_large.getSize().x) - 30.0f
    });

    Platform& small_platform_1 = platform_list[1];
    small_platform_1.setTexture(&img_platform_small);
    small_platform_1.setRenderPosition({175, 360});
    small_platform_1.setShape({
        static_cast<float>(small_platform_1.getRenderPosition().y) + static_cast<float>(img_platform_small.getSize().y) / 2.0f,
        static_cast<float>(small_platform_1.getRenderPosition().x) + 40.0f,
        static_cast<float>(small_platform_1.getRenderPosition().x) + static_cast<float>(img_platform_small.getSize().x) - 40.0f,
    });

    Platform& small_platform_2 = platform_list[2];
    small_platform_2.setTexture(&img_platform_small);
    small_platform_2.setRenderPosition({855, 360});
    small_platform_2.setShape({
        static_cast<float>(small_platform_2.getRenderPosition().y) + static_cast<float>(img_platform_small.getSize().y) / 2.0f,
        static_cast<float>(small_platform_2.getRenderPosition().x) + 40.0f,
        static_cast<float>(small_platform_2.getRenderPosition().x) + static_cast<float>(img_platform_small.getSize().x) - 40.0f,
    });

    Platform& small_platform_3 = platform_list[3];
    small_platform_3.setTexture(&img_platform_small);
    small_platform_3.setRenderPosition({855, 360});
    small_platform_3.setShape({
        static_cast<float>(small_platform_3.getRenderPosition().y) + static_cast<float>(img_platform_small.getSize().y) / 2.0f,
        static_cast<float>(small_platform_3.getRenderPosition().x) + 40.0f,
        static_cast<float>(small_platform_3.getRenderPosition().x) + static_cast<float>(img_platform_small.getSize().x) - 40.0f,
    });

}

void GameScene::onExit() {

}

void GameScene::onUpdate(const size_t delta) {

}

void GameScene::onDraw(const Camera& camera) {
    drawTexture(camera, pos_img_sky_, img_sky);
    drawTexture(camera, pos_img_hills_, img_hills);

    for (const Platform& platform : platform_list) {
        platform.onDraw(camera);
    }

    if (is_debug) {
        drawText({15, 15}, L"已开启调试模式");
    }
}

void GameScene::onInput(const sf::Event& event) {
    if (event.is<sf::Event::KeyPressed>()) {

        switch (event.getIf<sf::Event::KeyPressed>()->code)
        {
        case sf::Keyboard::Key::Q:
            is_debug = !is_debug;
            break;
        default:
            game_scene_manager.switchToScene(SceneManager::SceneType::MENU);
            break;
        }
    }
}
