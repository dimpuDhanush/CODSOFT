#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat image, processedImage;

void loadImage() {
    string path;
    cout << "Enter image path: ";
    cin >> path;
    image = imread(path);
    if (image.empty()) {
        cout << "Error: Unable to open image.\n";
        return;
    }
    processedImage = image.clone();
    imshow("Loaded Image", image);
    waitKey(0);
    destroyAllWindows();
}

void showImage() {
    if (processedImage.empty()) {
        cout << "No image loaded.\n";
        return;
    }
    imshow("Processed Image", processedImage);
    waitKey(0);
    destroyAllWindows();
}

void applyGrayscale() {
    if (processedImage.empty()) return;
    cvtColor(processedImage, processedImage, COLOR_BGR2GRAY);
    cvtColor(processedImage, processedImage, COLOR_GRAY2BGR);
    cout << "Grayscale applied.\n";
}

void applyBlur() {
    if (processedImage.empty()) return;
    GaussianBlur(processedImage, processedImage, Size(7, 7), 0);
    cout << "Blur applied.\n";
}

void applySharpen() {
    if (processedImage.empty()) return;
    Mat kernel = (Mat_<float>(3, 3) <<
         0, -1,  0,
        -1,  5, -1,
         0, -1,  0);
    filter2D(processedImage, processedImage, -1, kernel);
    cout << "Sharpen filter applied.\n";
}

void adjustBrightnessContrast() {
    if (processedImage.empty()) return;
    double alpha;
    int beta;
    cout << "Enter contrast (1.0–3.0): ";
    cin >> alpha;
    cout << "Enter brightness (-100 to 100): ";
    cin >> beta;
    processedImage.convertTo(processedImage, -1, alpha, beta);
    cout << "Brightness/Contrast adjusted.\n";
}

void resizeImage() {
    if (processedImage.empty()) return;
    int width, height;
    cout << "Enter new width: ";
    cin >> width;
    cout << "Enter new height: ";
    cin >> height;
    resize(processedImage, processedImage, Size(width, height));
    cout << "Image resized.\n";
}

void cropImage() {
    if (processedImage.empty()) return;
    int x, y, w, h;
    cout << "Enter x, y, width, height: ";
    cin >> x >> y >> w >> h;
    Rect roi(x, y, w, h);
    if (x + w > processedImage.cols || y + h > processedImage.rows) {
        cout << "Invalid crop dimensions.\n";
        return;
    }
    processedImage = processedImage(roi);
    cout << "Image cropped.\n";
}

void saveImage() {
    if (processedImage.empty()) return;
    string outPath;
    cout << "Enter output filename (e.g., result.jpg): ";
    cin >> outPath;
    imwrite(outPath, processedImage);
    cout << "Image saved to " << outPath << "\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- IMAGE PROCESSING TOOL ---\n";
        cout << "1. Load Image\n";
        cout << "2. Show Image\n";
        cout << "3. Apply Grayscale\n";
        cout << "4. Apply Blur\n";
        cout << "5. Apply Sharpen\n";
        cout << "6. Adjust Brightness/Contrast\n";
        cout << "7. Resize Image\n";
        cout << "8. Crop Image\n";
        cout << "9. Save Image\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: loadImage(); break;
            case 2: showImage(); break;
            case 3: applyGrayscale(); break;
            case 4: applyBlur(); break;
            case 5: applySharpen(); break;
            case 6: adjustBrightnessContrast(); break;
            case 7: resizeImage(); break;
            case 8: cropImage(); break;
            case 9: saveImage(); break;
            case 10: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}

