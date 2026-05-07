// service-worker.js
self.addEventListener("install", (event) => {
  event.waitUntil(
    caches.open("v3").then((cache) => {
      return cache.addAll([
        "/",
        "/index.html",
        "/manifest.json",
        "/service-worker.js"
      ]);
    })
  );
});

//poistaa vanhan cachen automaattisesti
self.addEventListener("activate", (event) => {
  event.waitUntil(
    caches.keys().then((keys) => {
      return Promise.all(
        keys.filter((key) => key !== "v2").map((key) => caches.delete(key))
      );
    })
  );
});

self.addEventListener("fetch", (event) => {
  event.respondWith(
    caches.match(event.request).then((response) => {
      return response || fetch(event.request);
    })
  );
});