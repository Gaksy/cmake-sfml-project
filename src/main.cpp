#include <SFML/Graphics.hpp>

#include "ResourcesUnit/ResourcesUtil.h"
#include "ResourcesUnit/Atlas.h"
#include "ResourcesUnit/SoundManager.h"
#include "Scene/GameScene.h"
#include "Scene/MenuScene.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "Scene/SelectorScene.h"
#include "SFML/Audio/SoundBuffer.hpp"


// 所需 图片/图集 变量的定义:
// 1.主菜单背景 图片
sf::Texture img_menu_background;      // 主菜单背景图片

// 2.选角界面的资源 图片
sf::Texture img_VS;                                       // VS 艺术字图片
sf::Texture img_1P;                                       // 1P 文本图片
sf::Texture img_2P;                                       // 2P 文本图片

sf::Texture img_1P_desc;                                  // 1P 键位描述图片
sf::Texture img_2P_desc;                                  // 2P 键位描述图片

sf::Texture img_gravestone_left;                          // 朝向左的墓碑图片
sf::Texture img_gravestone_right;                         // 朝向右的墓碑图片

sf::Texture img_selector_tip;                             // 选角界面提示文本图片
sf::Texture img_selector_background;                      // 选角界面背景图片

sf::Texture img_1P_selector_btn_idle_left;                // 1P 向左选择按钮默认状态图片
sf::Texture img_1P_selector_btn_idle_right;               // 1P 向右选择按钮默认状态图片
sf::Texture img_1P_selector_btn_down_left;                // 1P 向左选择按钮按下状态图片
sf::Texture img_1P_selector_btn_down_right;               // 1P 向右选择按钮按下状态图片

sf::Texture img_2P_selector_btn_idle_left;                // 2P 向左选择按钮默认状态图片
sf::Texture img_2P_selector_btn_idle_right;               // 2P 向右选择按钮默认状态图片
sf::Texture img_2P_selector_btn_down_left;                // 2P 向左选择按钮按下状态图片
sf::Texture img_2P_selector_btn_down_right;               // 2P 向右选择按钮按下状态图片

sf::Texture img_peashooter_selector_background_left;      // 选角界面朝向左的婉逗射手背景图片
sf::Texture img_peashooter_selector_background_right;     // 选角界面朝向右的婉逗射手背景图片

sf::Texture img_sunflower_selector_background_left;       // 选角界面朝向左的龙日葵背景图片
sf::Texture img_sunflower_selector_background_right;      // 选角界面朝向右的龙日葵背景图片

// 3.游戏界面的资源 图片
sf::Texture img_sky;                  // 天空图片
sf::Texture img_hills;                // 山脉图片
sf::Texture img_platform_large;       // 大型平台图片
sf::Texture img_platform_small;       // 小型平台图片

sf::Texture img_1P_cursor;            // 1P 指示光标图片
sf::Texture img_2P_cursor;            // 2P 指示光标图片

// 4.游戏(战斗)界面角色的的资源 图集
Atlas atlas_peashooter_idle_left;       // 婉逗射手朝向左的默认动画图集
Atlas atlas_peashooter_idle_right;      // 婉逗射手朝向右的默认动画图集
Atlas atlas_peashooter_run_left;        // 婉逗射手朝向左的跑步动画图集
Atlas atlas_peashooter_run_right;       // 婉逗射手朝向右的跑步动画图集
Atlas atlas_peashooter_attack_ex_left;  // 婉逗射手朝向左的攻击动画图集
Atlas atlas_peashooter_attack_ex_right; // 婉逗射手朝向右的攻击动画图集
Atlas atlas_peashooter_die_left;        // 婉逗射手朝向左的死亡动画图集
Atlas atlas_peashooter_die_right;       // 婉逗射手朝向右的死亡动画图集
Atlas atlas_sunflower_idle_left;        // 龙日葵朝向左的默认动画图集
Atlas atlas_sunflower_idle_right;       // 龙日葵朝向右的默认动画图集
Atlas atlas_sunflower_run_left;         // 龙日葵朝向左的跑步动画图集
Atlas atlas_sunflower_run_right;        // 龙日葵朝向右的跑步动画图集
Atlas atlas_sunflower_attack_ex_left;   // 龙日葵朝向左的攻击动画图集
Atlas atlas_sunflower_attack_ex_right;  // 龙日葵朝向右的攻击动画图集
Atlas atlas_sunflower_die_left;         // 龙日葵朝向左的死亡动画图集
Atlas atlas_sunflower_die_right;        // 龙日葵朝向右的死亡动画图集

// 5.游戏(战斗)界面其他的资源 图集
sf::Texture img_pea;        // 豌豆图片

Atlas atlas_pea_break;      // 豌豆破碎动画图集
Atlas atlas_sun;            // 日光动画图集
Atlas atlas_sun_explode;    // 日光爆炸动画图集
Atlas atlas_sun_ex;         // 特殊日光动画图集
Atlas atlas_sun_ex_explode; // 特殊日光爆炸动画图集
Atlas atlas_sun_text;       // “日” 文本动画图集

Atlas atlas_run_effect;     // 奔跑特效动画图集
Atlas atlas_jump_effect;    // 跳跃特效动画图集
Atlas atlas_land_effect;    // 落地特效动画图集

// 6.游戏结束界面的资源 图集
sf::Texture img_1P_winner;            // 1P 获胜文本图片
sf::Texture img_2P_winner;            // 2P 获胜文本图片
sf::Texture img_winner_bar;           // 获胜玩家背景文本图片

sf::Texture img_avatar_peashooter;    // 婉逗射手头像图片
sf::Texture img_avatar_sunflower;     // 龙日葵头像图片

// 音频管理器
SoundManager game_sound_manager;

Scene* p_menu_scene = nullptr;
Scene* p_game_scene = nullptr;
Scene* p_selector_scene = nullptr;

SceneManager game_scene_manager;

Camera main_camera;

void loadGameResources()
{
    // 1.主菜单背景 图片
    loadTextureFromFile(&img_menu_background, "resources/game_file/menu_background.png");                                           // 主菜单背景图片
    // 2.选角界面的资源 图片
    loadTextureFromFile(&img_VS, "resources/game_file/vs.png");                                                                     // VS 艺术字图片
    loadTextureFromFile(&img_1P, "resources/game_file/1P.png");                                                                     // 1P 文本图片
    loadTextureFromFile(&img_2P, "resources/game_file/2P.png");                                                                     // 2P 文本图片
    loadTextureFromFile(&img_1P_desc, "resources/game_file/1P_desc.png");                                                           // 1P 键位描述图片
    loadTextureFromFile(&img_2P_desc, "resources/game_file/2P_desc.png");                                                           // 2P 键位描述图片
    loadTextureFromFile(&img_gravestone_right, "resources/game_file/gravestone.png");                                               // 朝向左的墓碑图片
    flipTextureHorizontally(&img_gravestone_right, &img_gravestone_left);                                                                    // 朝向右的墓碑图片
    loadTextureFromFile(&img_selector_tip, "resources/game_file/selector_tip.png");                                                 // 选角界面提示文本图片
    loadTextureFromFile(&img_selector_background, "resources/game_file/selector_background.png");                                   // 选角界面背景图片
    loadTextureFromFile(&img_1P_selector_btn_idle_right, "resources/game_file/1p_selector_btn_idle.png");                           // 1P 向右选择按钮默认状态图片
    flipTextureHorizontally(&img_1P_selector_btn_idle_right, &img_1P_selector_btn_idle_left);                                                // 1P 向左选择按钮默认状态图片
    loadTextureFromFile(&img_1P_selector_btn_down_right, "resources/game_file/1p_selector_btn_down.png");                           // 1P 向右选择按钮默认状态图片
    flipTextureHorizontally(&img_1P_selector_btn_down_right, &img_1P_selector_btn_down_left);                                                // 1P 向左选择按钮按下状态图片
    loadTextureFromFile(&img_peashooter_selector_background_right, "resources/game_file/peashooter_selector_background.png");       // 选角界面朝向右的婉逗射手背景图片
    flipTextureHorizontally(&img_peashooter_selector_background_right, &img_peashooter_selector_background_left);                            // 选角界面朝向左的婉逗射手背景图片
    loadTextureFromFile(&img_sunflower_selector_background_right, "resources/game_file/sunflower_selector_background.png");         // 选角界面朝向右的龙日葵背景图片
    flipTextureHorizontally(&img_sunflower_selector_background_right, &img_sunflower_selector_background_left);                              // 选角界面朝向左的龙日葵背景图片

    // 3.游戏界面的资源 图片
    loadTextureFromFile(&img_sky, "resources/game_file/sky.png");                           // 天空图片
    loadTextureFromFile(&img_hills, "resources/game_file/hills.png");                       // 山脉图片
    loadTextureFromFile(&img_platform_large, "resources/game_file/platform_large.png");     // 大型平台图片
    loadTextureFromFile(&img_platform_small, "resources/game_file/platform_small.png");     // 小型平台图片

    loadTextureFromFile(&img_1P_cursor, "resources/game_file/1P_cursor.png");               // 1P 指示光标图片
    loadTextureFromFile(&img_2P_cursor, "resources/game_file/2P_cursor.png");               // 2P 指示光标图片

    // 4.游戏(战斗)界面角色的的资源 图集
    atlas_peashooter_idle_right.loadFromFile("resources/game_file/peashooter_idle_%d.png", 9);            // 婉逗射手朝向右的默认动画图集
    flipAtlasHorizontally(atlas_peashooter_idle_right, atlas_peashooter_idle_left);                      // 婉逗射手朝向左的默认动画图集
    atlas_peashooter_run_right.loadFromFile("resources/game_file/peashooter_run_%d.png", 5);              // 婉逗射手朝向右的跑步动画图集
    flipAtlasHorizontally(atlas_peashooter_run_right, atlas_peashooter_run_left);                        // 婉逗射手朝向左的跑步动画图集
    atlas_peashooter_attack_ex_right.loadFromFile("resources/game_file/peashooter_attack_ex_%d.png", 3);  // 婉逗射手朝向右的攻击动画图集
    flipAtlasHorizontally(atlas_peashooter_attack_ex_right, atlas_peashooter_attack_ex_left);            // 婉逗射手朝向左的攻击动画图集
    atlas_peashooter_die_right.loadFromFile("resources/game_file/peashooter_die_%d.png", 4);              // 婉逗射手朝向右的死亡动画图集
    flipAtlasHorizontally(atlas_peashooter_die_right, atlas_peashooter_die_left);                        // 婉逗射手朝向左的死亡动画图集
    atlas_sunflower_idle_right.loadFromFile("resources/game_file/sunflower_idle_%d.png", 8);              // 龙日葵朝向右的默认动画图集
    flipAtlasHorizontally(atlas_sunflower_idle_right, atlas_sunflower_idle_left);                        // 龙日葵朝向左的默认动画图集
    atlas_sunflower_run_right.loadFromFile("resources/game_file/sunflower_run_%d.png",5);                 // 龙日葵朝向右的跑步动画图集
    flipAtlasHorizontally(atlas_sunflower_run_right,atlas_sunflower_run_left);                           // 龙日葵朝向左的跑步动画图集
    atlas_sunflower_attack_ex_right.loadFromFile("resources/game_file/sunflower_attack_ex_%d.png",9);     // 龙日葵朝向右的攻击动画图集
    flipAtlasHorizontally(atlas_sunflower_attack_ex_right,atlas_sunflower_attack_ex_left);               // 龙日葵朝向左的攻击动画图集
    atlas_sunflower_die_right.loadFromFile("resources/game_file/sunflower_die_%d.png",2);                 // 龙日葵朝向右的死亡动画图集
    flipAtlasHorizontally(atlas_sunflower_die_right, atlas_sunflower_die_left);                          // 龙日葵朝向左的死亡动画图集

    // 5.游戏(战斗)界面其他的资源 图集
    loadTextureFromFile(&img_pea, "resources/game_file/pea.png");                                   // 豌豆图片
    atlas_pea_break.loadFromFile("resources/game_file/pea_break_%d.png",3);               // 豌豆破碎动画图集
    atlas_sun.loadFromFile("resources/game_file/sun_%d.png",5);                            // 日光动画图集
    atlas_sun_explode.loadFromFile("resources/game_file/sun_explode_%d.png",5);            // 日光爆炸动画图集
    atlas_sun_ex.loadFromFile("resources/game_file/sun_ex_%d.png",5);                      // 特殊日光动画图集
    atlas_sun_ex_explode.loadFromFile("resources/game_file/sun_ex_explode_%d.png", 5);     // 特殊日光爆炸动画图集
    atlas_sun_text.loadFromFile("resources/game_file/sun_text_%d.png",6);                  // “日” 文本动画图集

    atlas_run_effect.loadFromFile("resources/game_file/run_effect_%d.png",4);              // 奔跑特效动画图集
    atlas_jump_effect.loadFromFile("resources/game_file/jump_effect_%d.png",5);            // 跳跃特效动画图集
    atlas_land_effect.loadFromFile("resources/game_file/land_effect_%d.png",2);            // 落地特效动画图集

    // 6.游戏结束界面的资源 图集
    loadTextureFromFile(&img_1P_winner, "resources/game_file/1P_winner.png");                         // 1P 获胜文本图片
    loadTextureFromFile(&img_2P_winner, "resources/game_file/2P_winner.png");                         // 2P 获胜文本图片
    loadTextureFromFile(&img_winner_bar, "resources/game_file/winnner_bar.png");                      // 获胜玩家背景文本图片
    
    loadTextureFromFile(&img_avatar_peashooter, "resources/game_file/avatar_peashooter.png");         // 婉逗射手头像图片
    loadTextureFromFile(&img_avatar_sunflower, "resources/game_file/avatar_sunflower.png");           // 龙日葵头像图片

    // 添加音频资源
    game_sound_manager.loadSound("resources/game_file/bgm_game.mp3", "bgm_game");
    game_sound_manager.loadSound("resources/game_file/bgm_menu.mp3", "bgm_menu");
    game_sound_manager.loadSound("resources/game_file/pea_break_1.mp3", "pea_break_1");
    game_sound_manager.loadSound("resources/game_file/pea_break_2.mp3", "pea_break_2");
    game_sound_manager.loadSound("resources/game_file/pea_break_3.mp3", "pea_break_3");
    game_sound_manager.loadSound("resources/game_file/pea_shoot_1.mp3", "pea_shoot_1");
    game_sound_manager.loadSound("resources/game_file/pea_shoot_2.mp3", "pea_shoot_2");
    game_sound_manager.loadSound("resources/game_file/pea_shoot_ex.mp3", "pea_shoot_ex");
    game_sound_manager.loadSound("resources/game_file/ui_confirm.wav", "ui_confirm");
}

int main()
{
    // init window
    sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "Test", sf::Style::Close);
    window.setFramerateLimit(60);
    constexpr sf::Color backgroundColor = sf::Color::White;
    // open window
    window.clear(sf::Color::Black);
    window.display();

    // loadfile
    const sf::Font font("resources/font_file/NISC18030.ttf");
    loadGameResources();

    // init scene
    p_menu_scene = new MenuScene(font, &window);
    p_selector_scene = new SelectorScene(font, &window);
    p_game_scene = new GameScene(font, &window);
    game_scene_manager.setCurrentScene(p_menu_scene);

    // 计时
    sf::Clock clock;
    sf::Time last_time = clock.getElapsedTime();
    // start
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            if (event) {
                game_scene_manager.onInput(*event);
            }
        }

        sf::Time current_time = clock.getElapsedTime();
        sf::Time delta_time = current_time - last_time;
        last_time = current_time;

        game_scene_manager.onUpdate(delta_time.asMilliseconds());

        window.clear(backgroundColor);
        game_scene_manager.onDraw(main_camera);
        window.display();
    }

    delete p_menu_scene;
    delete p_game_scene;
}
