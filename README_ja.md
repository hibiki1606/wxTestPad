[English](/README.md)
# wxTestPad

C++, wxWidgetsとMesonを使用して書かれたテストプログラム

Windows, Linux, そして上手く行けばMacOS上でも動くはずです。

## Building (GCC on Arch Linux or MSYS2 ucrt64)

C++コンパイラ, Meson, そして少なくともバージョン3以上のwxWidgetsが必要です。

プロジェクトをビルドするために必要なヘッダーやクラスを生成するために、wxFormBuilderも必要です。ヘッダーやクラスは [これ](/gui/buildergen/TpGUI.fbp) をビルドすることで生成できます。

下記は常にシステムに依存するので、使用しているシステムにとって本当に最適なコマンドなのかを確認してから実行してください。

> Arch Linux上で必要なライブラリをインストール
```console
pacman -Syu
pacman -S meson wxwidgets-gtk3
```

> Windows上のMSYS2 (urct64)で必要なライブラリをインストール (MSYS2環境によって変わります)
```console
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-meson mingw-w64-ucrt-x86_64-wxwidgets3.2-msw
```

> Build... ([meson.build](/meson.build)があるディレクトリと同じ場所で)
```console
meson setup builddir
meson compile -C builddir
```

> Run...
```console
./builddir/wxTestPad
```

> [!IMPORTANT]
> このプログラムを使用して起きた・起きる可能性のある損害に対して私は一切の責任を負いません。
