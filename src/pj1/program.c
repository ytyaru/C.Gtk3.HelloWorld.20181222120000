#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
    //  親ウィンドウと GUI 要素（のポインタ変数）
    GtkWidget *window, *label;
    //  gtk+ の初期化（オマジナイ）
    gtk_init(&argc, &argv);

    //  親ウィンドウの生成（＋殺し方の指定）
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event",
                     G_CALLBACK(gtk_main_quit), NULL );
    //  ラベルの生成（＋親ウィンドウへの配置）
    label = gtk_label_new("Hello, world!");
    gtk_container_add(GTK_CONTAINER(window), label);

    //  GUI 要素・親ウィンドウの表示
    gtk_widget_show(label);
    gtk_widget_show(window);

    //  イベント処理ループ
    gtk_main();
}
