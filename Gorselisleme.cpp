/*
 * Proje: OpenCV Temel Arac Kutusu
 * Gelistiren: Ibrahim Tuncil
 * Aciklama: Goruntu, video ve cizim islemleri icin temel fonksiyonlar.
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;

void Gorselokuma(string resimyolu) {
    cv::Mat resim;
    resim = cv::imread(resimyolu);
    if (resim.data) {
        cv::namedWindow("pencere1");
        cv::imshow("pencere1", resim);
        cv::waitKey();
    }
    else {
        cout << "belirtilen yolda resim bulunamadi" << resimyolu << endl;
    }
    cv::destroyAllWindows();
}

void VideoOkuma(string videoyolu) {
    cv::VideoCapture video;
    video.open(videoyolu);
    int fps = 24;
    int tus;
    if (video.isOpened()) {
        cv::Mat frame;
        cv::namedWindow("pencere2");
        while (video.read(frame)) {
            cv::imshow("pencere2", frame);
            tus = cv::waitKey(1000 / fps);
            if(tus==27){
                break;
            }
            else if (tus == 43) {
                fps++;
                cout << "fps: " << fps << endl;
            }
            else if (tus == 45) {
                fps--;
                cout << "fps: " << fps << endl;
            }
         
        }
    }
    else {
        cout << "Dosya bulunamadı Dosya yolu: " << videoyolu << endl;
    }
}

void WebCamOkuma(int ch) {
    cv::VideoCapture video;
    if (video.open(ch)) {
        cout << "kamera algiladi" << endl;
        cv::namedWindow("pencere3");
        cv::Mat frame;
        int tus;
        while (video.grab()) {
            video.retrieve(frame);
            cv::flip(frame, frame, 1);
            cv::imshow("pencere3", frame);
           tus = cv::waitKey(1);
           if (tus == 27) {
               break;
           }
        }
    }
    else {
        cout << "kamera bulunamadi !" << endl;
    }
}

cv::Mat BasitResimOlusturma(int genislik, int yukseklik, int blue, int green, int red) {
    cv::Mat resim(genislik, yukseklik, CV_8UC3);
    resim = cv::Scalar(blue, green, red);
    return resim;
}

cv::Mat ResimKirpma(string dosyayolu, int x, int y, int genislik, int yukseklik)
{
    cv::namedWindow("pencere5");
    cv::Mat resim = cv::imread(dosyayolu);
    cv::imshow("pencere5", resim);
    cv::waitKey();
    cv::Mat kirpilmis;
    resim.copyTo(kirpilmis);
    kirpilmis = cv::Mat(kirpilmis, cv::Rect(x, y, genislik, yukseklik));
    return kirpilmis;
}

cv::Mat Cizgicizme(string dosyayolu) {
    cv::Mat resim = cv::imread(dosyayolu);
    cv::Mat cizilmisresim;
    resim.copyTo(cizilmisresim);
    cv::line(cizilmisresim, cv::Point(0, 0), cv::Point(200, 200), cv::Scalar(0, 0, 255), 5);
    return cizilmisresim;
}

cv::Mat DiktortgenCizme(string dosyayolu) {
    cv::Mat resim = cv::imread(dosyayolu);
    cv::Mat cizilmisresim;
    resim.copyTo(cizilmisresim);
    cv::rectangle(cizilmisresim,cv::Point(200,200),cv::Point(500,500),cv::Scalar(0,0,255),5);
    return cizilmisresim;
}

cv::Mat YaziYaz(string dosyayolu, string yazi) {
    cv::Mat resim = cv::imread(dosyayolu);
    cv::Mat yaziliresim;
    resim.copyTo(yaziliresim);
    cv::putText(yaziliresim, yazi, cv::Point(50, 200),cv::FONT_ITALIC,3,cv::Scalar(0,250,34),5);
    return yaziliresim;
}

cv::Mat DaireCiz(string dosyaYolu, int x, int y, int radius, int blue = 128, int green = 0, int red = 0, int kalinlik = 2) {
    cv::Mat resim = cv::imread(dosyaYolu);
    cv::Mat ciziliResim;
    resim.copyTo(ciziliResim);
    cv::Point merkez(x, y);
    cv::Scalar renk(blue, green, red);
    cv::circle(ciziliResim, merkez, radius, renk, kalinlik);
    return ciziliResim;
}

int main()
{
    int deger;
    string dosyayolu;
    string dosyayolu1;
    cout << "Uzerinde islem yapilacak resmin dosya yolunu girin" << endl;
    cin >> dosyayolu;
    cout << "Uzerinde islem yapilacak viedounun dosya yolunu girin" << endl;
    cin >> dosyayolu1;
    dosyayolu.erase(std::remove(dosyayolu.begin(), dosyayolu.end(), '"'), dosyayolu.end());
    dosyayolu1.erase(std::remove(dosyayolu1.begin(), dosyayolu1.end(), '"'), dosyayolu1.end());
    for (int i = 0;i < dosyayolu.length();i++) {
        if (dosyayolu[i] == '\\') {
            dosyayolu[i] = '/';
        }
    }
    for (int i = 0;i < dosyayolu1.length();i++) {
        if (dosyayolu1[i] == '\\') {
            dosyayolu1[i] = '/';
        }
    }
    cout << "Goruntu almak icin(Resim,Video,WebCam) 1'e basin" << endl;
    cout << "Resim olusturmak icin 2'ye basin" << endl;
    cout << "Cizme islemleri icin 3'e basin" << endl;
    cin >> deger;
    switch (deger) {
    case 1:
        cout << "gorsel almak icin 1'e basin" << endl;
        cout << "video almak icin 2'ye basin" << endl;
        cout << "WebCam'den goruntu almak icin 3'e basin" << endl;
        cin >> deger;
        switch (deger) {
        case 1:
            Gorselokuma(dosyayolu);
            break;
        case 2:
            VideoOkuma(dosyayolu1);
            break;
        case 3:
            WebCamOkuma(0);
            break;
        }
        break;
    case 2:
        cout << "1:Tek renkli resim olustur" << endl;
        cout << "2:kirpilmis resim olustur" << endl;
        cin >> deger;
        switch (deger) {
        case 1:{
                cv::Mat OlusturulanResim = BasitResimOlusturma(680, 480, 75, 200, 150);
                cv::imshow("pencere4", OlusturulanResim);
                cv::waitKey();
                break;
            }
        case 2:
            cv::imshow("pencere6", ResimKirpma(dosyayolu, 0 , 0, 800, 500));
            cv::waitKey();
            break;

        }
    case 3:
        cout << "duz bir cizgi cizmek icin 1'e basin" << endl;
        cout << "Diktortgen cizmek icin 2 ye basın" << endl;
        cout << "Yazi yazdirmak icin 3 e basin" << endl;
        cout << "Daire cizmek icin 4'e basin" << endl;
        cin >> deger;
        switch (deger){
        case 1:
            cv::imshow("pencere6", Cizgicizme(dosyayolu));
            cv::waitKey();
            break;
        case 2:
            cv::imshow("pencere7", DiktortgenCizme(dosyayolu));
            cv::waitKey();
            break;
        case 3:
            cv::imshow("pencere8", YaziYaz(dosyayolu,"ibrahim tuncil"));
            cv::waitKey();
            break;
        case 4:
            cv::imshow("pencere9", DaireCiz(dosyayolu, 300, 300, 200,100,150,25,5));
            cv::waitKey();
            break;
        }
    }

}
