#include <gtk/gtk.h>
//  ボタン用コールバック
void button_clicked (GtkWidget *widget, gpointer data)
{
    g_print("The button was clicked!\n");
}
//  メイン
int main (int argc, char *argv[])
{
    //  親ウィンドウと GUI 要素（のポインタ変数）
    GtkWidget *window, *button;
    //  gtk+ の初期化（オマジナイ）
    gtk_init(&argc, &argv);

    //  親ウィンドウの生成（＋殺し方の指定）
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event",
                     G_CALLBACK(gtk_main_quit), NULL );
    //  ボタンの生成（＋イベント処理の指定，＋親ウィンドウへの配置）
    button = gtk_button_new_with_label("Push me!");
    g_signal_connect(button, "clicked", 
                     G_CALLBACK(button_clicked), NULL );
    gtk_container_add(GTK_CONTAINER(window), button);

    //  GUI 要素・親ウィンドウの表示
    gtk_widget_show(button);
    gtk_widget_show(window);

    //  イベント処理ループ
    gtk_main();
}
