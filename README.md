# OpenCV-Toolkit-Cpp

[TR]
OpenCV Temel Araç Kütüphanesi

Görüntü işleme ve yapay zeka dünyasına sağlam bir giriş yapmak adına, C++ ve OpenCV kullanarak hazırladığım temel araç setini tamamladım.

Neden C++ tercih ettim?
Görüntü işleme ve oyun geliştirme süreçlerinde performans benim için en kritik öncelik. Donanıma yakın çalışmak, bellek yönetimini kontrol altında tutmak ve özellikle ileride geliştireceğim gerçek zamanlı AI sistemlerinde (Zombi AI vb.) en yüksek hıza ulaşmak için tercihim C++ oldu. Sektör standardı olan bu dilde derinleşmek, mimariyi daha iyi kavramamı sağlıyor.

Bu sürümde (v1.0) neler var?
- Görüntü, video ve canlı kamera akışı yönetimi.
- Dinamik FPS kontrolü ile video oynatma stabilitesi.
- Kullanıcı hatalarını (tırnak işareti, yanlış dosya yolu formatı vb.) otomatik düzelten string manipülasyon algoritmaları.
- Temel geometrik çizim araçları (Daire, dikdörtgen, yazı ekleme ve kırpma).

[EN]
Developing a C++ & OpenCV Toolbox

I am excited to share the first milestone of my journey into computer vision and AI! I have developed a foundational toolbox using C++ and OpenCV that focuses on core image processing tasks and user interaction.

Why C++?
Performance is my top priority. When building real-time systems like Image Processing tools or the AI-driven Game Dev projects I’m working on, I want to stay close to the hardware. C++ allows me to manage memory efficiently and ensures the high execution speed required for professional-grade vision applications and game engines like Unreal Engine.

Key Features (v1.0):
- Media Handling: Seamless reading of images, video files, and live webcam streams.
- Dynamic FPS Control: Real-time video playback adjustment for better stability.
- Defensive Programming: Implemented custom string manipulation algorithms to automatically clean user inputs (handling quotes, backslashes, and path formatting).
- Drawing & Manipulation: Tools for drawing shapes (circles, rectangles), adding text, and image cropping.
