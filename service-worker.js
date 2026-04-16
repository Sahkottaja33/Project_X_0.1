self.addEventListener("install", (event) => {
  event.waitUntil(
    caches.open("v1").then((cache) => {
      return cache.addAll([
        "/Project_X_0.1/",
        "/Project_X_0.1/index.html",
        "/Project_X_0.1/manifest.json"
      ]);
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
